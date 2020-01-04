#include "awm.h"

int		valid_sti(t_com *commands)
{
    if (commands->count_args != 3)
        return (0);
    return (valid_sti_arg(commands));
}

int		valid_fork(t_com *commands)
{
    if (commands->count_args != 1)
        return (0);
    return (valid_arg_dir(commands->arg1, commands));
}

int		valid_lfork(t_com *commands)
{
    if (commands->count_args != 1)
        return (0);
    return (valid_arg_dir(commands->arg1, commands));
}

int		valid_lld(t_com *commands)
{
    if (commands->count_args != 2)
        return (0);
    return (valid_lld_arg(commands));
}

int		valid_aff(t_com *commands)
{
    if (commands->count_args != 1)
        return (0);
    return (valid_arg_reg(commands->arg1));
}
