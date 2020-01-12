#include "awm.h"

void	delete_comment(char *str)
{
    int i;

    i = 0;
    if (!str)
		return;
    while (str[i] != '\0')
    {
        if (str[i] == '"')
        {
            i++;
            while (str[i] != '"' && str[i] != '\0')
                i++;
        }
        if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
        {
            str[i] = '\0';
            return;
        }
        i++;
    }
}