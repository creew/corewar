#include "awm.h"

int		valid_labeles(t_com *head)
{
    t_com *q;
    t_com *com;
    int flag[3];
	int row;

	row = 0;
    com = head;
    while (com)
    {
    	row++;
        flag[0] = 0;
        flag[1] = 0;
        flag[2] = 0;
        q = head;

        while (q)
        {
            if (com->arg1 && com->arg1[0] == '%' && com->arg1[1] == ':')
            {
                flag[0] == 0 ? flag[0] = 1 : 0;
                if (flag[0] == 1 && label_is(com->arg1 + 2, q))
                    flag[0] = 2;
            }
            if (com->arg1 && com->arg1[0] == ':')
            {
                flag[0] == 0 ? flag[0] = 1 : 0;
                if (flag[0] == 1 && label_is(com->arg1 + 1, q))
                    flag[0] = 2;
            }
            if (com->arg2 && com->arg2[0] == '%' && com->arg2[1] == ':')
            {
                flag[1] == 0 ? flag[1] = 1 : 0;
                if (flag[1] == 1 && label_is(com->arg2 + 2, q))
                    flag[1] = 2;
            }
            if (com->arg2 && com->arg2[0] == ':')
            {
                flag[1] == 0 ? flag[1] = 1 : 0;
                if (flag[1] == 1 && label_is(com->arg2 + 1, q))
                    flag[1] = 2;
            }
            if (com->arg3 && com->arg3[0] == '%' && com->arg3[1] == ':')
            {
                flag[2] == 0 ? flag[2] = 1 : 0;
                if (flag[2] == 1 && label_is(com->arg3 + 2, q))
                    flag[2] = 2;
            }
            if (com->arg3 && com->arg3[0] == ':')
            {
                flag[2] == 0 ? flag[2] = 1 : 0;
                if (flag[2] == 1 && label_is(com->arg3 + 1, q))
                    flag[2] = 2;
            }
            if (!q->next)
                break;
            q = q->next;
        }
        if (flag[0] == 1 || flag[1] == 1 || flag[2] == 1)
            return (com->row);
        if (!com->next)
            break;
        com = com->next;
    }
    return (-1);
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