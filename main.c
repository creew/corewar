#include "awm.h"

void	ft_str_only_space(char *str)
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

void	ft_exit()
{
	ft_printf(RED("Error\n"));
	exit(0);
}

int main(int argc, char **argv)
{
	int fd;
	char *line;
	char **str;
	t_ch player;
	int len;
	
	player.fd = open(argv[1], O_RDONLY);
	player.name = NULL;
	player.comment = NULL;
	while (get_next_line(player.fd, &line) > 0)
	{
//		ft_printf("%s", line);
//		ft_str_only_space(line);
//		str = ft_my_strsplit(line, ' ');
//		if (ft_strcmp(str[0], NAME_CMD_STRING) == 0)
//		{
//			if (player.name != NULL)
//				ft_exit();
//			if (str[1])
//				player.name = str[1];
//			else
//				ft_exit();
//			if (str[2] != NULL)
//				ft_exit();
//		}
//		else if (ft_strcmp(str[0], COMMENT_CMD_STRING) == 0)
//		{
//			if (player.comment != NULL)
//				ft_exit();
//			if (str[1])
//				player.comment = str[1];
//			else
//				ft_exit();
//			if (str[2])
//				ft_exit();
//		}
	}
	ft_printf("%s\n", player.comment);
	ft_printf("%s\n", player.name);
}