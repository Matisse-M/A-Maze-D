/*
** EPITECH PROJECT, 2023
** main
** File description:
** Minishell 1
*/

#include <stdlib.h>
#include "graph.h"

link_t **my_realloc_struct(link_t **link, int size)
{
    link_t **new = NULL;

    if (link == NULL) {
        new = malloc(sizeof(link_t *) * (size + 1));
        for (int i = 0; i <= size; i++) {
            new[i] = NULL;
        }
        return new;
    }
    new = malloc(sizeof(link_t *) * (my_structlen(link) + size + 1));
    for (int i = 0; i < my_structlen(link); i++)
        new[i] = link[i];
    for (int i = 0; i <= size; i++)
        new[my_structlen(link) + i] = NULL;
    return new;
}
