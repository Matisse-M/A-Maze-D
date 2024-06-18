/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** write a charcter string
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char **my_realloc_array(char **array, int size)
{
    char **new = NULL;

    if (array == NULL) {
        new = malloc(sizeof(char *) * (size + 1));
        for (int i = 0; i <= size; i++)
            new[i] = NULL;
        return new;
    }
    new = malloc(sizeof(char *) * (my_tablen(array) + size + 1));
    for (int i = 0; i < my_tablen(array); i++)
        new[i] = my_strdup(array[i]);
    for (int i = 0; i <= size; i++)
        new[my_tablen(array) + i] = NULL;
    return new;
}

char *my_realloc_str(char *str, int size)
{
    char *new = NULL;

    if (str == NULL) {
        new = malloc(sizeof(char) * (size + 1));
        for (int i = 0; i <= size; i++)
            new[i] = '\0';
        return new;
    }
    new = malloc(sizeof(char) * (my_strlen(str) + size + 1));
    for (int i = 0; i < my_strlen(str); i++)
        new[i] = str[i];
    for (int i = 0; i <= size; i++)
        new[my_strlen(str) + i] = '\0';
    return new;
}
