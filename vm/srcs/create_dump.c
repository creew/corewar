//
// Created by eklompus on 29.12.2019.
//

#include "vm.h"
#include <ft_printf.h>

static void		print_one_line(t_fieldelem *elem, int size, int pos)
{
	int		i;

	ft_printf("0x%04x :", pos);
	i = -1;
	while (++i < size)
		ft_printf(" %02x", elem[i].cmd);
	ft_printf("\n");
}

void			create_dump(t_vm *vm, int chars_in_line)
{
	int				memsize;
	t_fieldelem		*elems;
	int 			pos;
	int				size;

	pos = 0;
	memsize = sizeof(vm->field) / sizeof(vm->field[0]);
	elems = vm->field;
	while (pos < memsize)
	{
		size = ft_min(memsize - pos, chars_in_line);
		print_one_line(elems, size, pos);
		elems += size;
		pos += size;
	}
}