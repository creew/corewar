#include "awm.h"

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