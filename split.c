#include "awm.h"

int		count_words(char const *s, char c)
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
			while (*s != '"' && *s != '\0')
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

int		ft_word_length(char const *s, char c)
{
	size_t		i;
	
	i = 0;
	while (*s && *s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
