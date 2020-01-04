#include "awm.h"

int		valid_live(t_com *commands)
{
    if (commands->count_args != 1)
        return (0);
    return (valid_arg_dir(commands->arg1, commands));
}

int		valid_ld_arg(t_com *commands)
{
    if (!valid_arg_dir(commands->arg1, commands) && !valid_arg_int(commands->arg1))
        return(0);
    if (!valid_arg_reg(commands->arg2))
        return (0);
    return (1);
}
