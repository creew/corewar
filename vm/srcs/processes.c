/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:18:09 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 17:18:09 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"




void 	process_ld(t_process *pr, t_runner *run)
{
	t_uint	arg;
	long	a1;
	long	reg;

	a1 = 0;
	if (run->types[0] == DIR_CODE)
		a1 = run->args[0];
	else (run->types[0] == IND_CODE)
	a1 = read_be_map(run->field, pr->pc + run->types[0], DIR_SIZE, 1);

	pr->carry = a1 == 0;
	write_varlen_be(pr->regs[reg - 1], a1, REG_SIZE);

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg) == 0)
		{
			pr->carry = a1 == 0;
			write_varlen_be(pr->regs[reg - 1], a1, REG_SIZE);
		}
	}
	else
		ft_putendl("Error invalid arg2");
}













void 	process_live(t_vm *vm, t_process *pr, int *offset)
{
	t_uint arg = read_be_map(vm->field, pr->pc, DIR_SIZE, 1);
}

void 	process_ld(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	a1;
	long	reg;

	a1 = 0;
	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);
	if (((arg >> 6u) & 0x3u) == DIR_CODE)
		a1 = read_dir(vm->field, pr->pc, offset, 0);
	else if (((arg >> 6u) & 0x3u) == IND_CODE)
		a1 = read_ind(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("Error invalid arg1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg) == 0)
		{
			pr->carry = a1 == 0;
			write_varlen_be(pr->regs[reg - 1], a1, REG_SIZE);
		}
	}
	else
		ft_putendl("Error invalid arg2");
}

void 	process_st(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	a1;
	long	reg1;
	long	reg2;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);
	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg1) != 0)
			ft_putendl("st error invalid reg 1");
	}
	else
		ft_putendl("st error invalid 1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg2) == 0)
			ft_memcpy(pr->regs[reg2 - 1], pr->regs[reg1 - 1], sizeof(pr->regs));
		else
			ft_putendl("st error invalid reg 2");
	}
	else if (((arg >> 4u) & 0x3u) == IND_CODE)
	{
		a1 = read_ind(vm->field, pr->pc, offset, 1);
		set_field_vals(vm->field, pr->pc + a1, pr, reg1);
	}
	else
		ft_putendl("st error invalid 2");
}

void 	process_add(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	reg1;
	long	reg2;
	long	reg3;
	long	res;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);
	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg1) != 0)
			ft_putendl("add error invalid reg 1");
	}
	else
		ft_putendl("add error invalid 1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg2) != 0)
			ft_putendl("add error invalid reg 2");
	}
	else
		ft_putendl("add error invalid 2");

	if (((arg >> 2u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg3) != 0)
			ft_putendl("add error invalid reg 3");
		else
		{
			res = read_varlen_be(pr->regs[reg1], sizeof(pr->regs[0]));
			res += read_varlen_be(pr->regs[reg2], sizeof(pr->regs[0]));
			write_varlen_be(pr->regs[reg3], res, sizeof(pr->regs[0]));
			pr->carry = res == 0;
		}
	}
	else
		ft_putendl("add error invalid 3");
}

void 	process_sub(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	reg1;
	long	reg2;
	long	reg3;
	long	res;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);
	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg1) != 0)
			ft_putendl("sub error invalid reg 1");
	}
	else
		ft_putendl("sub error invalid 1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg2) != 0)
			ft_putendl("sub error invalid reg 2");
	}
	else
		ft_putendl("sub error invalid 2");

	if (((arg >> 2u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg3) != 0)
			ft_putendl("sub error invalid reg 3");
		else
		{
			res = read_varlen_be(pr->regs[reg1], sizeof(pr->regs[0]));
			res -= read_varlen_be(pr->regs[reg2], sizeof(pr->regs[0]));
			write_varlen_be(pr->regs[reg3], res, sizeof(pr->regs[0]));
			pr->carry = res == 0;
		}
	}
	else
		ft_putendl("sub error invalid 3");
}

void 	process_and(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	val1;
	long	val2;
	long	reg3;
	long	res;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);

	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val1) != 0)
			ft_putendl("and error invalid reg 1");
	}
	else if (((arg >> 6u) & 0x3u) == DIR_CODE)
		val1 = read_dir(vm->field, pr->pc, offset, 0);
	else if (((arg >> 6u) & 0x3u) == IND_CODE)
		val1 = read_ind(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("and error invalid 1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val2) != 0)
			ft_putendl("and error invalid reg 2");
	}
	else if (((arg >> 4u) & 0x3u) == DIR_CODE)
		val2 = read_dir(vm->field, pr->pc, offset, 0);
	else if (((arg >> 4u) & 0x3u) == IND_CODE)
		val2 = read_ind(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("and error invalid 2");

	if (((arg >> 2u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg3) != 0)
			ft_putendl("and error invalid reg 3");
		else
		{
			res = val1 & val2;
			write_varlen_be(pr->regs[reg3], res, sizeof(pr->regs[0]));
			pr->carry = res == 0;
		}
	}
	else
		ft_putendl("and error invalid 3");
}

void 	process_or(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	val1;
	long	val2;
	long	reg3;
	long	res;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);

	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val1) != 0)
			ft_putendl("or error invalid reg 1");
	}
	else if (((arg >> 6u) & 0x3u) == DIR_CODE)
		val1 = read_dir(vm->field, pr->pc, offset, 0);
	else if (((arg >> 6u) & 0x3u) == IND_CODE)
		val1 = read_ind(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("or error invalid 1");


	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val2) != 0)
			ft_putendl("or error invalid reg 2");
	}
	else if (((arg >> 4u) & 0x3u) == DIR_CODE)
		val2 = read_dir(vm->field, pr->pc, offset, 0);
	else if (((arg >> 4u) & 0x3u) == IND_CODE)
		val2 = read_ind(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("or error invalid 2");

	if (((arg >> 2u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg3) != 0)
			ft_putendl("or error invalid reg 3");
		else
		{
			res = val1 | val2;
			write_varlen_be(pr->regs[reg3], res, sizeof(pr->regs[0]));
			pr->carry = res == 0;
		}
	}
	else
		ft_putendl("or error invalid 3");
}

void 	process_xor(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	val1;
	long	val2;
	long	reg3;
	long	res;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);

	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val1) != 0)
			ft_putendl("xor error invalid reg 1");
	}
	else if (((arg >> 6u) & 0x3u) == DIR_CODE)
		val1 = read_dir(vm->field, pr->pc, offset, 0);
	else if (((arg >> 6u) & 0x3u) == IND_CODE)
		val1 = read_ind(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("xor error invalid 1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val2) != 0)
			ft_putendl("xor error invalid reg 2");
	}
	else if (((arg >> 4u) & 0x3u) == DIR_CODE)
		val2 = read_dir(vm->field, pr->pc, offset, 0);
	else if (((arg >> 4u) & 0x3u) == IND_CODE)
		val2 = read_ind(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("xor error invalid 2");

	if (((arg >> 2u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg3) != 0)
			ft_putendl("xor error invalid reg 3");
		else
		{
			res = val1 ^ val2;
			write_varlen_be(pr->regs[reg3], res, sizeof(pr->regs[0]));
			pr->carry = res == 0;
		}
	}
	else
		ft_putendl("xor error invalid 3");
}

void 	process_zjmp(t_vm *vm, t_process *pr, int *offset)
{
	long	val;
	if (pr->carry)
	{
		val = read_dir(vm->field, pr->pc, offset, 1);
		pr->pc += (val % IDX_MOD);
		*offset = 0;
	}
}

void 	process_ldi(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	val1;
	long	val2;
	long	reg3;
	t_ulong val;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);
	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val1) != 0)
			ft_putendl("ldi error invalid reg 1");
	}
	else if (((arg >> 6u) & 0x3u) == DIR_CODE)
		val1 = read_dir(vm->field, pr->pc, offset, 1);
	else if (((arg >> 6u) & 0x3u) == IND_CODE)
		val1 = read_ind(vm->field, pr->pc, offset, 0);
	else
		ft_putendl("ldi error invalid 1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val2) != 0)
			ft_putendl("ldi error invalid reg 2");
	}
	else if (((arg >> 4u) & 0x3u) == DIR_CODE)
		val2 = read_dir(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("ldi error invalid 2");

	if (((arg >> 2u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg3) != 0)
			ft_putendl("ldi error invalid reg 3");
		else
		{
			val = read_be_map(vm->field, pr->pc + (val1 + val2) % IDX_MOD,
				DIR_SIZE, 0);
			write_varlen_be(pr->regs[reg3 - 1], val, DIR_SIZE);
		}
	}
	else
		ft_putendl("ldi error invalid 3");
}

void 	process_sti(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	reg1;
	long	val2;
	long	val3;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);
	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg1) != 0)
			ft_putendl("sti error invalid reg 1");
	}
	else
		ft_putendl("sti error invalid 1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val2) != 0)
			ft_putendl("sti error invalid reg 2");
	}
	else if (((arg >> 4u) & 0x3u) == DIR_CODE)
		val2 = read_dir(vm->field, pr->pc, offset, 1);
	else if (((arg >> 4u) & 0x3u) == IND_CODE)
		val2 = read_ind(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("sti error invalid 2");

	if (((arg >> 2u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val3) != 0)
			ft_putendl("sti error invalid reg 2");
	}
	else if (((arg >> 2u) & 0x3u) == DIR_CODE)
		val3 = read_dir(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("sti error invalid 3");

	set_field_vals(vm->field, pr->pc + (val2 + val3) % IDX_MOD, pr, reg1);
}

void 	process_fork(t_vm *vm, t_process *pr, int *offset)
{
	long	arg;

	arg = read_dir(vm->field, pr->pc, offset, 1);
	copy_process(&vm->processes_root, pr, &vm->process_max, pr->pc + arg % IDX_MOD);
}

void 	process_lld(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	a1;
	long	reg;

	a1 = 0;
	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);
	if (((arg >> 6u) & 0x3u) == DIR_CODE)
		a1 = read_dir(vm->field, pr->pc, offset, 0);
	else if (((arg >> 6u) & 0x3u) == IND_CODE)
		a1 = read_ind(vm->field, pr->pc, offset, 0);
	else
		ft_putendl("Error invalid arg1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg) == 0)
		{
			pr->carry = a1 == 0;
			write_varlen_be(pr->regs[reg - 1], a1, REG_SIZE);
		}
	}
	else
		ft_putendl("Error invalid arg2");
}

void 	process_lldi(t_vm *vm, t_process *pr, int *offset)
{
	t_uint	arg;
	long	val1;
	long	val2;
	long	reg3;
	t_ulong val;

	arg = (t_uint)read_be_map(vm->field, pr->pc + (*offset)++, 1, 0);
	if (((arg >> 6u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val1) != 0)
			ft_putendl("lldi error invalid reg 1");
	}
	else if (((arg >> 6u) & 0x3u) == DIR_CODE)
		val1 = read_dir(vm->field, pr->pc, offset, 1);
	else if (((arg >> 6u) & 0x3u) == IND_CODE)
		val1 = read_ind(vm->field, pr->pc, offset, 0);
	else
		ft_putendl("lldi error invalid 1");

	if (((arg >> 4u) & 0x3u) == REG_CODE)
	{
		if (read_reg_val(vm->field, pr, offset, &val2) != 0)
			ft_putendl("lldi error invalid reg 2");
	}
	else if (((arg >> 4u) & 0x3u) == DIR_CODE)
		val2 = read_dir(vm->field, pr->pc, offset, 1);
	else
		ft_putendl("lldi error invalid 2");

	if (((arg >> 2u) & 0x3u) == REG_CODE)
	{
		if (read_register(vm->field, pr->pc, offset, &reg3) != 0)
			ft_putendl("lldi error invalid reg 3");
		else
		{
			val = read_be_map(vm->field, pr->pc + (val1 + val2) ,
							  DIR_SIZE, 0);
			write_varlen_be(pr->regs[reg3 - 1], val, DIR_SIZE);
		}
	}
	else
		ft_putendl("lldi error invalid 3");
}

void 	process_lfork(t_vm *vm, t_process *pr, int *offset)
{
	long	arg;

	arg = read_dir(vm->field, pr->pc, offset, 1);
	copy_process(&vm->processes_root, pr, &vm->process_max, pr->pc + arg);
}

void 	process_aff(t_vm *vm, t_process *pr, int *offset)
{


}

void (*g_asm_funcs[])(t_vm *vm, t_process *pr, int *offset) = {
	process_live,
	process_ld,
	process_st,
	process_add,
	process_sub,
	process_and,
	process_or,
	process_xor,
	process_zjmp,
	process_ldi,
	process_sti,
	process_fork,
	process_lld,
	process_lldi,
	process_lfork,
	process_aff
};

void	process_waiting(t_vm *vm, t_process *pr)
{
	int offset;
	int	skip;

	if (pr->wait > 0)
		pr->wait--;
	if (pr->wait == 0)
	{
		offset = 1;
		if (pr->opcode >= 1 && pr->opcode <= 16)
		{
			skip = 0;
			ft_putnbr(pr->opcode);
			ft_putendl(get_op_by_id(pr->opcode)->name);
			if (check_arguments(vm, pr, pr->opcode, &skip) == 0)
				g_asm_funcs[pr->opcode - 1](vm, pr, &offset);
			else
				offset += skip;
		}
		pr->pc += offset;
		pr->pc %= MEM_SIZE;
		pr->state = NOT_INITED;
	}
}

void	process_processes(t_vm *vm)
{
	t_process	*pr;
	t_uchar		id;
	t_op		*op;

	pr = vm->processes_root;
	while (pr)
	{
		if (pr->state == NOT_INITED)
		{
			id = read_be_map(vm->field, pr->pc, 1, 0);
			if ((op = get_op_by_id(id)) != NULL)
				pr->wait = op->wait;
			else
				pr->wait = 0;
			pr->state = WAITING;
			pr->opcode = id;
		}
		if (pr->state == WAITING)
			process_waiting(vm, pr);
		pr = pr->next;
	}
}