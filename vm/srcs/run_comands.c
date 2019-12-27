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

void 	process_live_run(t_process *pr, t_runner *run)
{
	t_uint arg;

	arg = run->args[0];
}

void 	process_ld_run(t_process *pr, t_runner *run)
{
	long	a1;

	a1 = 0;
	if (run->types[0] == DIR_CODE)
		a1 = run->args[0];
	else if (run->types[0] == IND_CODE)
		a1 = read_be_map(run->field, pr->pc + (run->args[0] % IDX_MOD),
						 DIR_SIZE, 1);

	pr->carry = a1 == 0;
	write_varlen_be(pr->regs[run->args[1] - 1], a1, REG_SIZE);
}

void 	process_st_run(t_process *pr, t_runner *run)
{
	if (run->types[1] == REG_CODE)
		ft_memcpy(pr->regs[run->args[1] - 1], pr->regs[run->args[0] - 1],
				  sizeof(pr->regs));
	else if (run->types[1] == IND_CODE)
		set_field_vals(run->field, pr->pc + (run->args[1] % IDX_MOD),
					   pr, run->args[0]);
}

void 	process_add_run(t_process *pr, t_runner *run)
{
	long	res;

	res = read_varlen_be(pr->regs[run->args[0] - 1], sizeof(pr->regs[0]));
	res += read_varlen_be(pr->regs[run->args[1] - 1], sizeof(pr->regs[0]));
	write_varlen_be(pr->regs[run->args[2] - 1], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_sub_run(t_process *pr, t_runner *run)
{
	long	res;

	res = read_varlen_be(pr->regs[run->args[0] - 1], sizeof(pr->regs[0]));
	res -= read_varlen_be(pr->regs[run->args[1] - 1], sizeof(pr->regs[0]));
	write_varlen_be(pr->regs[run->args[2] - 1], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_and_run(t_process *pr, t_runner *run)
{
	long	val1;
	long	val2;
	long	res;

	if (run->types[0] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[0] - 1], sizeof(pr->regs[0]));
	else if (run->types[0] == DIR_CODE)
		val1 = run->args[0];
	else if (run->types[0] == IND_CODE)
		val1 = read_be_map(run->field, pr->pc + (run->args[0] % IDX_MOD), DIR_SIZE, 1);

	if (run->types[1] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[1] - 1], sizeof(pr->regs[0]));
	else if (run->types[1] == DIR_CODE)
		val2 = run->args[1];
	else if (run->types[1] == IND_CODE)
		val2 = read_be_map(run->field, pr->pc + (run->args[1] % IDX_MOD), DIR_SIZE, 1);

	res = val1 & val2;
	write_varlen_be(pr->regs[run->args[2]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_or_run(t_process *pr, t_runner *run)
{
	long	val1;
	long	val2;
	long	res;

	if (run->types[0] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[0] - 1], sizeof(pr->regs[0]));
	else if (run->types[0] == DIR_CODE)
		val1 = run->args[0];
	else if (run->types[0] == IND_CODE)
		val1 = read_be_map(run->field, pr->pc + (run->args[0] % IDX_MOD), DIR_SIZE, 1);

	if (run->types[1] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[1] - 1], sizeof(pr->regs[0]));
	else if (run->types[1] == DIR_CODE)
		val2 = run->args[1];
	else if (run->types[1] == IND_CODE)
		val2 = read_be_map(run->field, pr->pc + (run->args[1] % IDX_MOD), DIR_SIZE, 1);

	res = val1 | val2;
	write_varlen_be(pr->regs[run->args[2]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_xor_run(t_process *pr, t_runner *run)
{
	long	val1;
	long	val2;
	long	res;

	if (run->types[0] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[0] - 1], sizeof(pr->regs[0]));
	else if (run->types[0] == DIR_CODE)
		val1 = run->args[0];
	else if (run->types[0] == IND_CODE)
		val1 = read_be_map(run->field, pr->pc + (run->args[0] % IDX_MOD), DIR_SIZE, 1);

	if (run->types[1] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[1] - 1], sizeof(pr->regs[0]));
	else if (run->types[1] == DIR_CODE)
		val2 = run->args[1];
	else if (run->types[1] == IND_CODE)
		val2 = read_be_map(run->field, pr->pc + (run->args[1] % IDX_MOD), DIR_SIZE, 1);

	res = val1 ^ val2;
	write_varlen_be(pr->regs[run->args[2]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
}

void 	process_zjmp_run(t_process *pr, t_runner *run)
{
	if (pr->carry)
	{
		pr->pc += (int)(run->args[0] % IDX_MOD);
		run->skip = 0;
	}
}

void 	process_ldi_run(t_process *pr, t_runner *run)
{
	long	val1;
	long	val2;
	t_ulong val;

	if (run->types[0] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[0] - 1], sizeof(pr->regs[0]));
	else if (run->types[0] == DIR_CODE)
		val1 = run->args[0];
	else if (run->types[0] == IND_CODE)
		val1 = read_be_map(run->field, pr->pc + (run->args[0] % IDX_MOD), DIR_SIZE, 1);


	if (run->types[1] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[1] - 1], sizeof(pr->regs[0]));
	else if (run->types[1] == DIR_CODE)
		val2 = run->args[1];

	val = read_be_map(run->field, pr->pc + (val1 + val2) % IDX_MOD, DIR_SIZE, 0);
	write_varlen_be(pr->regs[run->args[2] - 1], val, DIR_SIZE);
}

void 	process_sti_run(t_process *pr, t_runner *run)
{
	long	val2;
	long	val3;

	if (run->types[1] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[1] - 1], sizeof(pr->regs[0]));
	else if (run->types[1] == DIR_CODE)
		val2 = run->args[1];
	else if (run->types[1] == IND_CODE)
		val2 = read_be_map(run->field, pr->pc + (run->args[1] % IDX_MOD), DIR_SIZE, 1);

	if (run->types[2] == REG_CODE)
		val3 = read_varlen_be(pr->regs[run->args[2] - 1], sizeof(pr->regs[0]));
	else if (run->types[2] == DIR_CODE)
		val3 = run->args[2];

	set_field_vals(run->field, pr->pc + (val2 + val3) % IDX_MOD, pr, run->args[0]);
}

void 	process_fork_run(t_process *pr, t_runner *run)
{
	copy_process(run->processes_root, pr, run->process_max,
		pr->pc + run->args[0] % IDX_MOD);
}

void 	process_lld_run(t_process *pr, t_runner *run)
{
	long	a1;

	a1 = 0;
	if (run->types[0] == DIR_CODE)
		a1 = run->args[0];
	else if (run->types[0] == IND_CODE)
		a1 = read_be_map(run->field, pr->pc + run->args[0], DIR_SIZE, 1);

	pr->carry = a1 == 0;
	write_varlen_be(pr->regs[run->args[1] - 1], a1, REG_SIZE);
}

void 	process_lldi_run(t_process *pr, t_runner *run)
{
	long	val1;
	long	val2;
	t_ulong val;

	if (run->types[0] == REG_CODE)
		val1 = read_varlen_be(pr->regs[run->args[0] - 1], sizeof(pr->regs[0]));
	else if (run->types[0] == DIR_CODE)
		val1 = run->args[0];
	else if (run->types[0] == IND_CODE)
		val1 = read_be_map(run->field, pr->pc + run->args[0], DIR_SIZE, 1);

	if (run->types[1] == REG_CODE)
		val2 = read_varlen_be(pr->regs[run->args[1] - 1], sizeof(pr->regs[0]));
	else if (run->types[1] == DIR_CODE)
		val2 = run->args[1];

	val = read_be_map(run->field, pr->pc + (val1 + val2), DIR_SIZE, 0);
	write_varlen_be(pr->regs[run->args[2] - 1], val, DIR_SIZE);
}

void 	process_lfork_run(t_process *pr, t_runner *run)
{
	copy_process(run->processes_root, pr, run->process_max,
		pr->pc + run->args[0]);
}

void 	process_aff_run(t_process *pr, t_runner *run)
{

}
