#include "awm.h"

int		valid_ld(t_com *commands)
{
    if (commands->count_args != 2)
        return (0);
    return (valid_ld_arg(commands));
}

int		valid_st(t_com *commands)
{
    if (commands->count_args != 2)
        return (0);
    return (valid_st_arg(commands));
}

int		valid_add(t_com *commands)
{
    if (commands->count_args != 3)
        return (0);
    return (valid_add_arg(commands));
}

int		valid_sub(t_com *commands)
{
    if (commands->count_args != 3)
        return (0);
    return (valid_sub_arg(commands));
}

int		valid_and(t_com *commands)
{
    if (commands->count_args != 3)
        return (0);
    return (valid_and_arg(commands));
}