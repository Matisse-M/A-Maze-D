/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** Return 1 if digits if not 0
*/

#include <stdlib.h>
#include "my.h"

int my_isnum(char const *str)
{
    char *dup = NULL;

    if (str == NULL)
        return (1);
    dup = my_strdup(str);
    for (int i = 0; dup[i] != '\0'; i++) {
        if ((dup[i] < '0' || dup[i] > '9'))
            return (0);
    }
    return (1);
}

int myis_num(char const *str)
{
    char *dup = NULL;

    if (str == NULL)
        return (1);
    dup = my_strdup(str);
    for (int i = 0; dup[i] != '\0'; i++) {
        if (i == 0 && dup[i] == '0')
            return 0;
        if ((dup[i] < '0' || dup[i] > '9'))
            return (0);
    }
    return (1);
}

int my_str_num(char const *str)
{
    char **dup = NULL;
    int j = 0;

    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            j += 1;
    }
    if (j < 2)
        return 0;
    dup = my_str_to_word_array(str);
    for (int i = 1; dup[i] != NULL; i++) {
        if (my_isnum(dup[i]) == 0)
            return 0;
    }
    return (1);
}

int my_str_isnum(char const *str)
{
    char *dup = NULL;

    if (str == NULL)
        return (1);
    dup = my_strdup(str);
    for (int i = 0; dup[i] != '\0'; i++) {
        if ((dup[i] < '1' || dup[i] > '9'))
            return (0);
    }
    return (1);
}
