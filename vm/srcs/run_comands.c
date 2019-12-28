/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_comands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 10:40:16 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/27 10:40:16 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 	process_live_run(t_vm *vm, t_process *pr, t_runner *run)
{

	pr->cycle_live = vm->cycles;
	vm->live++;
}

void 	process_ld_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	a1;

	if (run->types[A1] == DIR_CODE)
		a1 = run->args[A1];
	else
		a1 = read_be_map(vm->field, pr->pc + (run->args[A1] % IDX_MOD),
						 DIR_SIZE, 1);
	write_varlen_be(pr->regs[run->args[A2]], a1, sizeof(pr->regs[0]));
	pr->carry = a1 == 0;
}

void 	process_st_run(t_vm *vm, t_process *pr, t_runner *run)
{
	if (run->types[A2] == REG_CODE)
		ft_memcpy(pr->regs[run->args[A2]], pr->regs[run->args[A1]],
				  sizeof(pr->regs[0]));
	else
		set_field_vals(vm->field, pr->pc + (run->args[A2] % IDX_MOD),
					   pr, run->args[A1]);
}

void 	process_add_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	res;

	res = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	res += read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	write_varlen_be(pr->regs[run->args[A3]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_sub_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	res;

	res = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	res -= read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	write_varlen_be(pr->regs[run->args[A3]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_and_run(t_vm *vm, t_process *pr, t_runner *run)
{
	t_ulong		val1;
	t_ulong		val2;
	t_ulong		res;

	if (run->types[A1] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A1] == DIR_CODE)
		val1 = run->args[A1];
	else
		val1 = read_be_map(vm->field, pr->pc + (run->args[A1] % IDX_MOD), DIR_SIZE, SIGNED);

	if (run->types[A2] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A2] == DIR_CODE)
		val2 = run->args[A2];
	else
		val2 = read_be_map(vm->field, pr->pc + (run->args[A2] % IDX_MOD), DIR_SIZE, SIGNED);

	res = val1 & val2;
	write_varlen_be(pr->regs[run->args[A3]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_or_run(t_vm *vm, t_process *pr, t_runner *run)
{
	t_ulong		val1;
	t_ulong		val2;
	t_ulong		res;

	if (run->types[A1] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A1] == DIR_CODE)
		val1 = run->args[A1];
	else
		val1 = read_be_map(vm->field, pr->pc + (run->args[A1] % IDX_MOD), DIR_SIZE, SIGNED);

	if (run->types[A2] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A2] == DIR_CODE)
		val2 = run->args[A2];
	else
		val2 = read_be_map(vm->field, pr->pc + (run->args[A2] % IDX_MOD), DIR_SIZE, SIGNED);

	res = val1 | val2;
	write_varlen_be(pr->regs[run->args[A3]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_xor_run(t_vm *vm, t_process *pr, t_runner *run)
{
	t_ulong		val1;
	t_ulong 	val2;
	t_ulong		res;

	if (run->types[A1] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A1] == DIR_CODE)
		val1 = run->args[A1];
	else
		val1 = read_be_map(vm->field, pr->pc + (run->args[A1] % IDX_MOD), DIR_SIZE, SIGNED);

	if (run->types[A2] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A2] == DIR_CODE)
		val2 = run->args[A2];
	else
		val2 = read_be_map(vm->field, pr->pc + (run->args[A2] % IDX_MOD), DIR_SIZE, 0);

	res = val1 ^ val2;
	write_varlen_be(pr->regs[run->args[A3]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_zjmp_run(t_vm *vm, t_process *pr, t_runner *run)
{
	if (pr->carry)
	{
		pr->pc += (int)(run->args[A1] % IDX_MOD);
		while (pr->pc < 0)
			pr->pc += MEM_SIZE;
		run->skip = 0;
	}
}

void 	process_ldi_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	val1;
	long	val2;
	t_ulong val;

	if (run->types[A1] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A1] == DIR_CODE)
		val1 = run->args[A1];
	else
		val1 = read_be_map(vm->field, pr->pc + (run->args[A1] % IDX_MOD), DIR_SIZE, SIGNED);

	if (run->types[A2] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	else
		val2 = run->args[A2];

	val = read_be_map(vm->field, pr->pc + (val1 + val2) % IDX_MOD, DIR_SIZE, 0);
	write_varlen_be(pr->regs[run->args[A3]], val, DIR_SIZE);
}

void 	process_sti_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	val2;
	long	val3;

	if (run->types[A2] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A2] == DIR_CODE)
		val2 = run->args[A2];
	else
		val2 = read_be_map(vm->field, pr->pc + (run->args[A2] % IDX_MOD), DIR_SIZE, SIGNED);

	if (run->types[A3] == REG_CODE)
		val3 = read_varlen_be(pr->regs[run->args[A3]], sizeof(pr->regs[0]), SIGNED);
	else
		val3 = run->args[A3];

	set_field_vals(vm->field, pr->pc + (val2 + val3) % IDX_MOD, pr, run->args[A1]);
}

void 	process_fork_run(t_vm *vm, t_process *pr, t_runner *run)
{
	copy_process(&vm->processes_root, pr, &vm->process_max,
		pr->pc + run->args[A1] % IDX_MOD);
}

void 	process_lld_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	a1;

	a1 = 0;
	if (run->types[A1] == DIR_CODE)
		a1 = run->args[A1];
	else if (run->types[A1] == IND_CODE)
		a1 = read_be_map(vm->field, pr->pc + run->args[A1], DIR_SIZE / 2, SIGNED);

	write_varlen_be(pr->regs[run->args[A2]], a1, REG_SIZE);
	pr->carry = a1 == 0;
}

void 	process_lldi_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	val1;
	long	val2;
	t_ulong val;

	if (run->types[A1] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	else if (run->types[A1] == DIR_CODE)
		val1 = run->args[A1];
	else
		val1 = read_be_map(vm->field, pr->pc + run->args[A1] % IDX_MOD, DIR_SIZE, SIGNED);

	if (run->types[A2] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	else
		val2 = run->args[A2];

	val = read_be_map(vm->field, pr->pc + (val1 + val2), DIR_SIZE, SIGNED);
	write_varlen_be(pr->regs[run->args[A3]], val, DIR_SIZE);
}

void 	process_lfork_run(t_vm *vm, t_process *pr, t_runner *run)
{
	copy_process(&vm->processes_root, pr, &vm->process_max,
		pr->pc + run->args[A1]);
}

void 	process_aff_run(t_vm *vm, t_process *pr, t_runner *run)
{

}
