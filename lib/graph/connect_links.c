/*
** EPITECH PROJECT, 2023
** main
** File description:
** Minishell 1
*/

#include "../../include/my.h"
#include "graph.h"

void connect_links(link_t *link1, link_t *link2)
{
    link_t *temp = link2;

    link1->link = my_realloc_struct(link1->link, 1);
    link2->link = my_realloc_struct(link2->link, 1);
    link2->link[my_structlen(link2->link)] = link1;
    link1->link[my_structlen(link1->link)] = temp;
}
