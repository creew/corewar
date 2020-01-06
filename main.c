#include "awm.h"

void		set_player(t_ch *player, char *str)
{
	char *line;
	char *q;

	player->name = NULL;
	player->comment = NULL;
	player->fd = open(str, O_RDONLY);
	while (get_next_line(player->fd, &line) > 0)
	{
		q = ft_strtrim(line);
		clear_line(&line);
		line = q;
		delete_comment(q);
		ft_delete_tabs(q);
		if (it_s_name(q))
			add_name(q, player);
		else if (it_s_comment(q))
			add_comment(q, player);
		else if (*q != '\0' && *q != '\n')
			ft_exit();
		if (player->name != NULL && player->comment != NULL)
			break;
		clear_line(&line);
	}
	clear_line(&line);
}

void	wokr_with_label(char *q, t_com **commands, t_valid validator)
{
	add_label(q, *commands);
	if (!valid_label((*commands)->label))
		ft_exit();
	if(l_and_c_one_rows(q))
	{
		add_command_with_label(&q, *commands);
		if (command_is_valid((*commands)->name, validator))
		{
			add_args(&q, *commands);
			if(!valid_args(*commands, validator))
				ft_exit();
		}
		(*commands)->next = lst_create_commands();
		*commands = (*commands)->next;
	}
}

void	work_with_command(char *q, t_com **commands, t_valid validator)
{
	add_command(q, *commands);
	add_args(&q, *commands);
	if(!valid_args(*commands, validator))
		ft_exit();
	(*commands)->next = lst_create_commands();
	*commands = (*commands)->next;
}

void	set_commands(t_ch player, t_com *commands)
{
	char *line;
	char *q;
	t_valid		validator;

	init_validator(&validator);
	while (get_next_line(player.fd, &line) > 0)
	{
		init_line(&line, &q);
		if (it_s_label(q))
			wokr_with_label(q, &commands, validator);
		else if (*q != '\0' && is_command(q, validator))
			work_with_command(q, &commands, validator);
		else if (*q != '\0')
			ft_exit();
		clear_line(&line);
	}
}

int main (int main, char **argv)
{
	char		*line;
	t_ch		player;
	t_com		*commands;
	t_com		*commands_head;

	commands = lst_create_commands();
	commands_head = commands;
	set_player(&player, argv[1]);
	set_commands(player, commands);
	clear_line(&line);
	if (!valid_labeles(commands_head))
		ft_exit();
	if (commands_head->name == NULL)
		ft_exit();
	printf("name ----        %s\ncomment  ------     %s\n", player.name, player.comment);
	printf(GREEN("ok"));
	clear_commands(&commands);
	clear_player(&player);
	return (0);
}