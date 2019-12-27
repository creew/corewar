#include "awm.h"

void	init_command(void)
{
	ft_strcpy(can_use_command[0],"live");
	ft_strcpy(can_use_command[1], "ld");
	ft_strcpy(can_use_command[2], "st");
	ft_strcpy(can_use_command[3], "add");
	ft_strcpy(can_use_command[4], "sub");
	ft_strcpy(can_use_command[5], "and");
	ft_strcpy(can_use_command[6], "or");
	ft_strcpy(can_use_command[7], "xor");
	ft_strcpy(can_use_command[8], "zjmp");
	ft_strcpy(can_use_command[9], "ldi");
	ft_strcpy(can_use_command[10], "sti");
	ft_strcpy(can_use_command[11], "fork");
	ft_strcpy(can_use_command[12], "lld");
	ft_strcpy(can_use_command[13], "lldi");
	ft_strcpy(can_use_command[14], "lfork");
	ft_strcpy(can_use_command[15], "aff");
}

void	init_args()
{
	ft_strcpy(can_use_args[0],"T_REG");
	ft_strcpy(can_use_args[1],"T_DIR");
	ft_strcpy(can_use_args[2],"T_INT");
}

void	lst_create_live(t_info info)
{
	ft_strcpy(info.live.args, "T_DIR");
	info.live.count_args = 1;
}

void	ft_exit(void)
{
	ft_printf(RED("Error\n"));
	exit(0);
}

t_com	*lst_create_commands(void)
{
	t_com *commands;

	commands = (t_com *) malloc(sizeof(t_com));
	commands->arg1 = NULL;
	commands->arg2 = NULL;
	commands->arg3 = NULL;
	commands->label = NULL;
	commands->name = NULL;
	commands->count_args = 0;
	return (commands);
}

int		it_s_label(char *line)
{
	int i;
	char **str;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == LABEL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

void	add_label(char *line, t_com *commands)
{
	if (commands->label)
	{
		ft_strjoin(commands->label, " ");
		ft_strjoin(commands->label, ft_my_strsplit(line, LABEL_CHAR)[0]);
	}
	else
		commands->label = ft_my_strsplit(line, LABEL_CHAR)[0];
}

void	ft_delete_tabs(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
}

int		l_and_c_one_rows(char *line)
{
	int i;

	i = 0;
	while (line[i] != LABEL_CHAR)
		i++;
	if (line[i + 1] && line[i + 1] != '\0')
		return (1);
	return (0);
}

void	add_command_with_label(char **line, t_com *command)
{
	int i;

	while (**line != LABEL_CHAR)
		(*line)++;
	(*line)++;
	*line = ft_strtrim(*line);
	command->name = (char *)malloc(sizeof(char *) * (ft_strchr(*line, ' ') - *line + 1));
	ft_strncpy(command->name, *line, ft_strchr(*line, ' ') - *line);
}

int		command_is_valid(char *command)
{
	int i;

	i = 0;
	while (can_use_command[i])
	{
		if (ft_strcmp(command, can_use_command[i]) == 0)
			return (1);
		i++;
	}
	ft_exit();
	return (0);
}

void		add_args(char **line, t_com *commands)
{
	char **args;
	int		i;

	while (**line != ' ')
		(*line)++;
	args = ft_my_strsplit(*line, SEPARATOR_CHAR);
	if (args[0])
	{
		commands->arg1 = ft_strtrim(args[0]);
		commands->count_args++;
	}
	if (args[1])
	{
		commands->arg2 = ft_strtrim(args[1]);
		commands->count_args++;
	}
	if (args[2])
	{
		commands->arg3 = ft_strtrim(args[2]);
		commands->count_args++;
	}
}

int		valid_arg_reg(t_com *commands)
{

}

int		valid_live(t_com *commands, t_info info)
{
	int		i;

	if (commands->count_args != info.live.count_args)
		return (0);
	valid_arg_reg(commands->arg1);
}


int		valid_args(t_com *commands, t_valid validator, t_info info)
{
	int	i;

	i = 0;
	while (ft_strcmp(can_use_command[i], commands->name) != 0)
		i++;
	if (validator.valid_com[i](commands, info))
		return (1);
	return (0);
}


void	init_validator(t_valid *validator)
{
	validator->valid_com[0] = &valid_live;
}

int main (int main, char **argv)
{
	char	*line;
	int		i;
	t_ch	player;
	t_com	*commands;
	t_info	info;
	init_command();
	init_args();
	t_valid		validator;

	init_validator(&validator);
	commands = lst_create_commands();
	player.fd = open(argv[1], O_RDONLY);
	lst_create_live(info);
	while (get_next_line(player.fd, &line) > 0)
	{
		ft_delete_tabs(line);
		line = ft_strtrim(line);
		if (it_s_label(line))
		{
			add_label(line, commands);
			if(l_and_c_one_rows(line))
			{
				add_command_with_label(&line, commands);
				if (command_is_valid(commands->name))
				{
					add_args(&line, commands);
					valid_args(commands, validator);
				}
			}
		}
	}
	printf("%s\n", commands->label);
	printf("%s\n", commands->name);
	printf("%s\n", commands->arg1);
	printf("%s\n", commands->arg2);
	printf("%s\n", commands->arg3);
}