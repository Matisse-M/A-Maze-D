/*
** EPITECH PROJECT, 2023
** main
** File description:
** Minishell 1
*/

#include <stdlib.h>
#include "graph.h"

link_t *create_link(int data)
{
    link_t *link = malloc(sizeof(link_t));

    link->data = data;
    link->link = NULL;
    return link;
}
