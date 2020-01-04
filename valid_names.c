#include "awm.h"

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