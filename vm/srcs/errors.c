/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:08:43 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:08:46 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"

static t_errdesc	g_errs[] = {
	{ERR_OPEN_CHAMP, "Error opening champion"},
	{ERR_READ_CHAMP, "Error reading champion"},
	{ERR_WRONG_MAGIC, "Wrong magic in champion file"},
	{ERR_CHAMP_TO_BIG, "Champion size is bigger than it have to be"},
	{ERR_CHAMP_ZEROSIZE, "Champion size is zero"},
	{ERR_ENOMEM, "Couldn't allocate memory"},
	{ERR_READ_BODY_CHAMP, "Error reading body champion"},
	{ERR_NO_ARGUMENTS, "No arguments passed to exe file"},
	{ERR_TO_LITTLE_PLAYERS, "Players count less than 2"},
	{ERR_TO_MUCH_PLAYERS, "Players more than MAX_PLAYERS"},
	{ERR_INCORRECT_ORDER_PLAYERS, "Wrong order players"},
	{ERR_INCORRECT_DUMPARG, "Wrong argument in -dump"},
	{ERR_INCORRECT_NARG, "Wrong argument in -n"},
	{ERR_INCORRECT_DARG, "Wrong argument in -d"},
	{ERR_CANT_ASSIGN_INDEX, "Can't assign index for player"}
};

static const char	g_usage[] =
"Usage: ./corewar_orig [-dump N | -d N | -v | -n ] [-a] <champion1.cor> <...>\n"
"    -a        : Prints output from \"aff\" (Default is to hide it)\n"
"#### TEXT OUTPUT MODE ###################"
"#######################################\n"
"    -dump N   : Dumps memory after N cycles then exits\n"
"    -d N      : Verbosity levels, can be added together to enable several\n"
"                - 0 : Show only essentials\n"
"                - 1 : Show lives\n"
"                - 2 : Show cycles\n"
"                - 4 : Show operations (Params are NOT litteral ...)\n"
"                - 8 : Show deaths\n"
"                - 16 : Show PC movements (Except for jumps)\n"
"#### SDL2 OUTPUT MODE ###################"
"#######################################\n"
"    -v        : Sdl2 graphic output mode\n"
"#### USE OWN ORDER CHAMP ################"
"#######################################\n"
"    -n <champ.cor>       : sets the number of the next player\n"
"#########################################"
"#######################################\n";

void	print_usage(void)
{
	ft_putstr(g_usage);
}

char	*get_error(t_result err)
{
	size_t	index;

	index = -1;
	while (++index < sizeof(g_errs) / sizeof(g_errs[0]))
	{
		if (err == g_errs[index].res)
			return (g_errs[index].name);
	}
	return (NULL);
}

void	print_error(t_result res)
{
	char	*txt;

	if ((txt = get_error(res)) != NULL)
		ft_putendl(txt);
	else
	{
		ft_putstr("Error: ");
		ft_putnbr(res);
		ft_putendl("");
	}
}
