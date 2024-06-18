/*
** EPITECH PROJECT, 2023
** main
** File description:
** Minishell 1
*/

#include <stdlib.h>
#include "graph.h"

int my_structlen(link_t **link)
{
    int size = 0;

    for (int i = 0; link[i] != NULL; i++)
        size++;
    return size;
}
