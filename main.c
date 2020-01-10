#include "awm.h"

void		set_player(t_ch *player, char *str)
{
	char *line;
	char *q;

	player->name = NULL;
	player->comment = NULL;
	player->fd = open(str, O_RDONLY);
	while (get_row(player->fd, &line) > 0)
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
			ft_exit2("недопустимые символы, должно быть имя или коммент чемпиона", player->row);
		if (player->name != NULL && player->comment != NULL)
			break;
		clear_line(&line);
	}
	if (!player->name || !player->comment)
		ft_exit2("не существует имени или коммента чимпиона", 0);
	clear_line(&line);
}

void	wokr_with_label(char *q, t_com **commands, t_valid validator, t_ch player)
{
	add_label(q, *commands);

	if (!valid_label((*commands)->label))
		ft_exit2("не валидная метка", player.row);
	if(l_and_c_one_rows(q))
	{
		add_command_with_label(&q, *commands);
		if (command_is_valid((*commands)->name, validator, player.row))
		{
			add_args(&q, *commands, player);
			if(!valid_args(*commands, validator))
				ft_exit2("не валидный аргумент", player.row);
		}
		(*commands)->row = player.row;
		(*commands)->next = lst_create_commands();
		*commands = (*commands)->next;
	}
}

void	work_with_command(char *q, t_com **commands, t_valid validator, t_ch player)
{
	add_command(q, *commands);
	add_args(&q, *commands, player);
	(*commands)->row = player.row;
	if(!valid_args(*commands, validator))
		ft_exit2("не валидный аргумент", player.row);
	(*commands)->next = lst_create_commands();
	*commands = (*commands)->next;
}

void	set_commands(t_ch *player, t_com *commands)
{
	char *line;
	char *q;
	t_valid		validator;

	init_validator(&validator);
	while (get_row(player->fd, &line) > 0)
	{
		player->row++;
		init_line(&line, &q);
		if (it_s_label(q))
			wokr_with_label(q, &commands, validator, *player);
		else if (*q != '\0' && is_command(q, validator, player->row))
			work_with_command(q, &commands, validator, *player);
		else if (*q != '\0')
			ft_exit2("не верный синтаксис", player->row);
		clear_line(&line);
	}
	if (if_the_end_file_with_out_n(line))
		ft_exit2("ожидался перенос строки", player->row);
}

int main (int main, char **argv)
{
	char *line;
	t_ch		player;
	t_com		*commands;
	t_com		*commands_head;
	int			row;

	line = NULL;
	commands = lst_create_commands();
	commands_head = commands;
	set_player(&player, argv[1]);
	set_commands(&player, commands);
	if (!commands->label && !commands->name)
		ft_exit2("нет команд", 0);
	if ((row = valid_labeles(commands_head)) != -1)
		ft_exit2("не сущесвует такой метки, которая в аргументе", row);
	clear_line(&line);
//	printf("name ----        %s\ncomment  ------     %s\n", player.name, player.comment);
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
//	printf("\n%d", player.row);
	clear_commands(&commands);
	clear_player(&player);
	return (0);
}