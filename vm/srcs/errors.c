//
// Created by eklompus on 07.01.2020.
//

#include "errors.h"
#include "libft.h"

static t_errdesc g_errs[] = {
	{ERR_OPEN_CHAMP, "Error opening champion"},
	{ERR_READ_CHAMP, "Error reading champion"},
	{ERR_WRONG_MAGIC, "Wrong magic in champion file"},
	{ERR_CHAMP_TO_BIG, "Champion size is bigger than it have to be"},
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

char	*get_error(t_result err)
{
	size_t 	index;

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
