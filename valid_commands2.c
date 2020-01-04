#include "awm.h"

int		valid_or(t_com *commands)
{
    if (commands->count_args != 3)
        return (0);
    return (valid_or_arg(commands));
}

int		valid_xor(t_com *commands)
{
    if (commands->count_args != 3)
        return (0);
    return (valid_xor_arg(commands));
}

int		valid_zjmp(t_com *commands)
{
    if (commands->count_args != 1)
        return (0);
    return (valid_arg_dir(commands->arg1, commands));
}

int		valid_ldi(t_com *commands)
{
    if (commands->count_args != 3)
        return (0);
    return (valid_ldi_arg(commands));
}

int		valid_lldi(t_com *commands)
{
    if (commands->count_args != 3)
        return (0);
    return (valid_lldi_arg(commands));
}