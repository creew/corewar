#include "awm.h"

static int		count_words(char const *s, char c)
{
	int			nb_words;
	int			str_test;
	
	nb_words = 0;
	str_test = 0;
	while (*s != '\0')
	{
		if (*s == '"')
		{
			nb_words++;
			s++;
			while (*s != '"')
				s++;
		}
		if (str_test == 1 && *s == c)
			str_test = 0;
		if (str_test == 0 && *s != c)
		{
			str_test = 1;
			nb_words++;
		}
		s++;
	}
	return (nb_words);
}

static int		ft_word_length(char const *s, char c)
{
	size_t		i;
	
	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_my_strsplit(char const *s, char c)
{
	char		**my_tab;
	int			i;
	int			nb_words;
	
	i = 0;
	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	my_tab = (char **)malloc(sizeof(char *) * nb_words + 1);
	if (my_tab == NULL)
		return (NULL);
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '"')
		{
			s++;
			(my_tab[i++] = ft_strsub(s, 0, ft_word_length(s, '"')));
			while (*s != '"' && *s != '\0')
				s++;
			if (*s != '\0')
				s++;
			nb_words--;
			continue;
		}
		if ((my_tab[i++] = ft_strsub(s, 0, ft_word_length(s, c))) == NULL)
		{
			free(my_tab);
			return (NULL);
		}
		s += ft_word_length(s, c);
	}
	my_tab[i] = NULL;
	return (my_tab);
}