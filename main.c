#include "awm.h"

void	clear_line(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

void	clear_player(t_ch *player)
{
		free(player->name);
		free(player->comment);
}

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
	commands->next = NULL;
	commands->count_args = 0;
	return (commands);
}

int		it_s_label(char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\0' && line[i] != DIRECT_CHAR)
	{
		if (line[i] == LABEL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

void	add_label(char *line, t_com *commands)
{
	char **str;
	char *q;

	str = ft_my_strsplit(line, LABEL_CHAR);
	if (commands->label)
	{
		q = ft_strdup(commands->label);
		free(commands->label);
		commands->label = ft_strjoin(q, " ");
		free(q);
		q = ft_strdup(commands->label);
		free(commands->label);
		commands->label = ft_strjoin(q, str[0]);
		free(q);
	}
	else
		commands->label = ft_strdup(str[0]);
	str[0] ? free(str[0]) : 0;
	str[1] ? free(str[1]) : 0;
	(str[2] && str[1]) ? free(str[2]) : 0;
	free(str);
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
	int n;
	char *q;

	n = 0;
	while (**line != LABEL_CHAR)
		(*line)++;
	(*line)++;
	q = ft_strtrim(*line);
	while (q[n] != ' ' && q[n] != '\0' && q[n] != DIRECT_CHAR && q[n] != '-')
		n++;
	if (n >= 0)
		command->name = ft_strsub(q, 0, n);
	free(q);
}

void	add_command(char *line, t_com *command)
{
	int i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0' && line[i] != DIRECT_CHAR && line[i] != '-')
		i++;
	command->name = ft_strsub(line, 0, i);
}

int		command_is_valid(char *command)
{
	int i;

	i = 0;
	while (i < 16 && command)
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
	char *s;
	char *q;

	s = ft_strtrim(*line);
	q = s;
	i = 0;
	while (*s != ' ' && *s != DIRECT_CHAR && *s != '-')
		s++;
	while (s[i] != '\0')
		i++;
	if (s[i - 1] == SEPARATOR_CHAR)
		ft_exit();
	args = ft_my_strsplit(s, SEPARATOR_CHAR);
	if (args[0])
	{
		commands->arg1 = ft_strtrim(args[0]);
		commands->count_args++;
		free(args[0]);
	}
	if (args[1])
	{
		commands->arg2 = ft_strtrim(args[1]);
		commands->count_args++;
		free(args[1]);
	}
	if (args[2])
	{
		commands->arg3 = ft_strtrim(args[2]);
		commands->count_args++;
		free(args[2]);
	}
	free(args);
	free(q);
}

int		label_is(char *str, t_com *commands)
{
	if (commands->label && ft_is_strstr(commands->label, str))
		return (1);
	return (0);
}

int		valid_arg_dir(char	*str, t_com *commands)
{

	if (str[0] == DIRECT_CHAR)
	{
		str++;
		if (*str == '-')
			str++;
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
				str++;
			if (*str == '\0')
				return (1);
		}
		if (*(str) == LABEL_CHAR && str[1] != '\0' && str[1] != ' ')
			return (1);
	}
	return (0);
}

int		valid_arg_int(char *str, t_com *commands)
{
	if (str[0] == LABEL_CHAR && str[1] != '\0' && str[1] != ' ')
		return (1);
	if (str[0] == '-' || str[0] == '+')
		str++;
	if (ft_isdigit(str[0]))
	{
		while (ft_isdigit(*str))
			str++;
		if (*str == '\0')
			return (1);
	}
	return (0);
}

int		valid_arg_reg(char *str)
{
	int n;

	if (str[0] == 'r')
	{
		str++;
		n = ft_atoi(str);
		if (n >= 0 && n <= REG_NUMBER)
		{
			while (ft_isdigit(*str))
				str++;
			if (*str == '\0')
				return (1);
		}
	}
	return (0);
}

int		valid_live(t_com *commands)
{
	if (commands->count_args != 1)
		return (0);
	return (valid_arg_dir(commands->arg1, commands));
}

int		valid_ld_arg(t_com *commands)
{
	if (!valid_arg_dir(commands->arg1, commands) && !valid_arg_int(commands->arg1, commands))
		return(0);
	if (!valid_arg_reg(commands->arg2))
		return (0);
	return (1);
}

int		valid_lld_arg(t_com *commands)
{
	if (!valid_arg_dir(commands->arg1, commands) && !valid_arg_int(commands->arg1, commands))
		return(0);
	if (!valid_arg_reg(commands->arg2))
		return (0);
	return (1);
}

int		valid_st_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1))
		return (0);
	if (!valid_arg_reg(commands->arg2) && !valid_arg_int(commands->arg2, commands))
		return(0);
	return (1);
}

int		valid_add_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) || !valid_arg_reg(commands->arg2) || !valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		valid_sub_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) || !valid_arg_reg(commands->arg2) || !valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		valid_and_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1, commands) && !valid_arg_dir(commands->arg1, commands))
		return (0);
	if (!valid_arg_reg(commands->arg2) && !valid_arg_int(commands->arg2, commands) && !valid_arg_dir(commands->arg2, commands))
		return (0);
	if (!valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		valid_or_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1, commands) && !valid_arg_dir(commands->arg1, commands))
		return (0);
	if (!valid_arg_reg(commands->arg2) && !valid_arg_int(commands->arg2, commands) && !valid_arg_dir(commands->arg2, commands))
		return (0);
	if (!valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		valid_xor_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1, commands) && !valid_arg_dir(commands->arg1, commands))
		return (0);
	if (!valid_arg_reg(commands->arg2) && !valid_arg_int(commands->arg2, commands) && !valid_arg_dir(commands->arg2, commands))
		return (0);
	if (!valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		valid_ldi_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1, commands) && !valid_arg_dir(commands->arg1, commands))
		return (0);
	if (!valid_arg_reg(commands->arg2) && !valid_arg_dir(commands->arg2, commands))
		return (0);
	if (!valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		valid_lldi_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) && !valid_arg_int(commands->arg1, commands) && !valid_arg_dir(commands->arg1, commands))
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
	if (!valid_arg_reg(commands->arg2) && !valid_arg_dir(commands->arg2, commands) && !valid_arg_int(commands->arg2, commands))
		return (0);
	if (!valid_arg_reg(commands->arg3) && !valid_arg_dir(commands->arg3, commands))
		return (0);
	return (1);
}

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

int		valid_args(t_com *commands, t_valid validator)
{
	int	i;

	i = 0;
	while (i < 15 && ft_strcmp(can_use_command[i], commands->name) != 0)
		i++;
	if (validator.valid_com[i](commands))
		return (1);
	return (0);
}

int		valid_aff(t_com *commands)
{
	if (commands->count_args != 1)
		return (0);
	return (valid_arg_reg(commands->arg1));
}

void	init_validator(t_valid *validator)
{
	validator->valid_com[0] = &valid_live;
	validator->valid_com[1] = &valid_ld;
	validator->valid_com[2] = &valid_st;
	validator->valid_com[3] = &valid_add;
	validator->valid_com[4] = &valid_sub;
	validator->valid_com[5] = &valid_and;
	validator->valid_com[6] = &valid_or;
	validator->valid_com[7] = &valid_xor;
	validator->valid_com[8] = &valid_zjmp;
	validator->valid_com[9] = &valid_ldi;
	validator->valid_com[10] = &valid_sti;
	validator->valid_com[11] = &valid_fork;
	validator->valid_com[12] = &valid_lld;
	validator->valid_com[13] = &valid_lldi;
	validator->valid_com[14] = &valid_lfork;
	validator->valid_com[15] = &valid_aff;
}

int		is_command(char *line)
{
	char *str;
	int i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0' && line[i] != DIRECT_CHAR && line[i] != '-')
		i++;
	str = ft_strsub(line, 0, i);
	if (str && command_is_valid(str))
	{
		free(str);
		return (1);
	}
	if (str)
		free(str);
	return (0);
}

void	add_with_n_name(t_ch *player, char *str)
{
	int i;
	char *line;
	char *s;

	line = NULL;
	if (!player->name)
		player->name = ft_strjoin(str, "\n");
	else
	{
		line = ft_strjoin(str, "\n");
		s = ft_strdup(player->name);
		free(player->name);
		player->name = ft_strjoin(s, line);
		free(s);
		free(line);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != '"')
		i++;
	if (str)
		free(str);
	if (str[i] == '\0')
	{
		get_next_line(player->fd, &line);
		add_with_n_name(player, line);
	}
	if (str[i] == '"')
	{
		i++;
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '\t')
				ft_exit();
			i++;
		}
	}
}

void	add_name(char *str, t_ch *player)
{
	int i;

	i = 1;
	if (player->name != NULL)
		ft_exit();
	while (*str != '"' && *str != '\0')
		str++;
	if (*str == '\0')
		ft_exit();
	while (str[i] != '"' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		add_with_n_name(player, ft_strdup(1 + str));
		if (ft_strlen(player->name) > PROG_NAME_LENGTH)
			ft_exit();
		return;
	}
	if (str[i] == '\0')
		ft_exit();
	if (str[i + 1] && str[i + 1] != '\0')
		ft_exit();
	player->name = ft_strsub(str, 1, i - 1);
	if (ft_strlen(player->name) > PROG_NAME_LENGTH)
		ft_exit();
}

int it_s_name(char *line)
{
	int i;
	char *str;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0' && line[i] != '"')
		i++;
	str = ft_strsub(line, 0, i);
	if (ft_strcmp(str, NAME_CMD_STRING) == 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}


void	add_with_n_comment(t_ch *player, char *str)
{
	int i;
	char *line;
	char *s;

	line = NULL;
	if (!player->comment)
		player->comment = ft_strjoin(str, "\n");
	else
	{
		line = ft_strjoin(str, "\n");
		s = ft_strdup(player->comment);
		free(player->comment);
		player->comment = ft_strjoin(s, line);
		free(s);
		free(line);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != '"')
		i++;
	if (str)
		free(str);
	if (str[i] == '\0')
	{
		get_next_line(player->fd, &line);
		add_with_n_comment(player, line);
	}
	if (str[i] == '"')
	{
		i++;
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '\t')
				ft_exit();
			i++;
		}
	}
}

void	add_comment(char *str, t_ch *player)
{
	int i;

	i = 1;
	if (player->comment != NULL)
		ft_exit();
	while (*str != '"' && *str != '\0')
		str++;
	if (*str == '\0')
		ft_exit();
	while (str[i] != '"' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		add_with_n_comment(player, ft_strdup(1 + str));
		if (ft_strlen(player->comment) > COMMENT_LENGTH)
			ft_exit();
		return;
	}
	if (str[i + 1] && str[i + 1] != '\0')
		ft_exit();
	player->comment = ft_strsub(str, 1, i - 1);
	if (ft_strlen(player->comment) > COMMENT_LENGTH)
		ft_exit();
}

int it_s_comment(char *line)
{
	int i;
	char *str;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	str = ft_strsub(line, 0, i);
	if (ft_strcmp(str, COMMENT_CMD_STRING) == 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int		valid_label(char *label)
{
	int i;
	int j;

	i = 0;
	while (label[i] != '\0')
	{
		j = 0;
		while (LABEL_CHARS[j] != '\0' && label[i] != LABEL_CHARS[j] && label[i] != ' ' && label[i] != DIRECT_CHAR)
			j++;
		if (LABEL_CHARS[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	delete_comment(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
		{
			str[i] = '\0';
			return;
		}
		i++;
	}
}

int		valid_labeles(t_com *head)
{
	t_com *q;
	t_com *com;
	int flag1;
	int flag2;
	int flag3;

	com = head;
	while (com)
	{
		flag1 = 0;
		flag2 = 0;
		flag3 = 0;
		q = head;
		while (q)
		{
			if (com->arg1 && com->arg1[0] == '%' && com->arg1[1] == ':')
			{
				flag1 == 0 ? flag1 = 1 : 0;
				if (flag1 == 1 && label_is(com->arg1 + 2, q))
					flag1 = 2;
			}
			if (com->arg1 && com->arg1[0] == ':')
			{
				flag1 == 0 ? flag1 = 1 : 0;
				if (flag1 == 1 && label_is(com->arg1 + 1, q))
					flag1 = 2;
			}
			if (com->arg2 && com->arg2[0] == '%' && com->arg2[1] == ':')
			{
				flag2 == 0 ? flag2 = 1 : 0;
				if (flag2 == 1 && label_is(com->arg2 + 2, q))
					flag2 = 2;
			}
			if (com->arg2 && com->arg2[0] == ':')
			{
				flag2 == 0 ? flag2 = 1 : 0;
				if (flag2 == 1 && label_is(com->arg2 + 1, q))
					flag2 = 2;
			}
			if (com->arg3 && com->arg3[0] == '%' && com->arg3[1] == ':')
			{
				flag3 == 0 ? flag3 = 1 : 0;
				if (flag3 == 1 && label_is(com->arg3 + 2, q))
					flag3 =2;
			}
			if (com->arg3 && com->arg3[0] == ':')
			{
				flag3 == 0 ? flag3 = 1 : 0;
				if (flag3 == 1 && label_is(com->arg3 + 1, q))
					flag3 = 2;
			}
			if (!q->next)
				break;
			q = q->next;
		}
		if (flag1 == 1 || flag2 == 1 || flag3 == 1)
			return (0);
		if (!com->next)
			break;
		com = com->next;
	}
	return (1);
}

void	clear_commands(t_com **coms)
{
	t_com *q;

	while (*coms && (*coms)->next)
	{
		q = *coms;
		(*coms) = (*coms)->next;
		free(q->name);
		free(q->arg2);
		free(q->arg1);
		free(q->arg3);
		free(q->label);
		free(q);
	}
	free((*coms)->name);
	free((*coms)->arg2);
	free((*coms)->label);
	free((*coms)->arg1);
	free((*coms)->arg3);
	free(*coms);
}

int main (int main, char **argv)
{
	char	*line;
	int		i;
	t_ch	player;
	t_com	*commands;
	t_com	*commands_head;
	t_com	*p;
	char *q;
	init_command();
	init_args();
	t_valid		validator;

	init_validator(&validator);
	player.name = NULL;
	q = NULL;
	player.comment = NULL;
	commands = lst_create_commands();
	commands_head = commands;
	player.fd = open(argv[1], O_RDONLY);
	while (get_next_line(player.fd, &line) > 0)
	{
		q = ft_strtrim(line);
		clear_line(&line);
		line = q;
		delete_comment(q);
		ft_delete_tabs(q);
		if (it_s_name(q))
			add_name(q, &player);
		else if (it_s_comment(q))
			add_comment(q, &player);
		else if (*q != '\0' && *q != '\n')
			ft_exit();
		if (player.name != NULL && player.comment != NULL)
			break;
		clear_line(&line);
	}
	clear_line(&line);
	while (get_next_line(player.fd, &line) > 0)
	{
		delete_comment(line);
		ft_delete_tabs(line);
		q = ft_strtrim(line);
		clear_line(&line);
		line = q;
		if (it_s_label(q))
		{
			add_label(q, commands);
			if (!valid_label(commands->label))
				ft_exit();
			if(l_and_c_one_rows(q))
			{
				add_command_with_label(&q, commands);
				if (command_is_valid(commands->name))
				{
					add_args(&q, commands);
					if(!valid_args(commands, validator))
						ft_exit();
				}
				commands->next = lst_create_commands();
				commands = commands->next;
				clear_line(&line);
				continue;
			}
			clear_line(&line);
			continue;
		}
		if (*q != '\0' && is_command(q))
		{
			add_command(q, commands);
			add_args(&q, commands);

			if(!valid_args(commands, validator))
				ft_exit();
			commands->next = lst_create_commands();
			commands = commands->next;
		}
		else if (*q != '\0')
			ft_exit();
		clear_line(&line);
	}
	i = 0;
	clear_line(&line);
	if (!valid_labeles(commands_head))
		ft_exit();
	if (commands_head->name == NULL)
		ft_exit();
	commands = commands_head;
//	while (commands_head->next)
//	{
//		printf("%s\n", commands_head->label);
//		printf("%s\n", commands_head->name);
//		printf("%s\n", commands_head->arg1);
//		printf("%s\n", commands_head->arg2);
//		printf("%s\n", commands_head->arg3);
//		printf("--------------------------\n");
//		commands_head = commands_head->next;
//	}
	printf(GREEN("ok"));
	clear_commands(&commands);
	clear_player(&player);
	return (0);
}