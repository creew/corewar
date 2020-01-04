#include "awm.h"

int		valid_xor_arg(t_com *commands)
{
    if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1) && !valid_arg_dir(commands->arg1, commands))
        return (0);
    if (!valid_arg_reg(commands->arg2) && !valid_arg_int(commands->arg2) && !valid_arg_dir(commands->arg2, commands))
        return (0);
    if (!valid_arg_reg(commands->arg3))
        return (0);
    return (1);
}

int		valid_ldi_arg(t_com *commands)
{
    if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1) && !valid_arg_dir(commands->arg1, commands))
        return (0);
    if (!valid_arg_reg(commands->arg2) && !valid_arg_dir(commands->arg2, commands))
        return (0);
    if (!valid_arg_reg(commands->arg3))
        return (0);
    return (1);
}

int		valid_lldi_arg(t_com *commands)
{
    if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1) && !valid_arg_dir(commands->arg1, commands))
        return (0);
    if (!valid_arg_reg(commands->arg2) && !valid_arg_dir(commands->arg2, commands))
        return (0);
    if (!valid_arg_reg(commands->arg3))
        return (0);
    return (1);
}

int		valid_sti_arg(t_com *commands)
{
    if (!valid_arg_reg(commands->arg1))
        return (0);
    if (!valid_arg_reg(commands->arg2) && !valid_arg_dir(commands->arg2, commands) && !valid_arg_int(commands->arg2))
        return (0);
    if (!valid_arg_reg(commands->arg3) && !valid_arg_dir(commands->arg3, commands))
        return (0);
    return (1);
}

int		valid_or_arg(t_com *commands)
{
    if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1) && !valid_arg_dir(commands->arg1, commands))
        return (0);
    if (!valid_arg_reg(commands->arg2) && !valid_arg_int(commands->arg2) && !valid_arg_dir(commands->arg2, commands))
        return (0);
    if (!valid_arg_reg(commands->arg3))
        return (0);
    return (1);
}