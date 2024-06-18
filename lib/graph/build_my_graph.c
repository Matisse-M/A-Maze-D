/*
** EPITECH PROJECT, 2023
** main
** File description:
** Minishell 1
*/

#include <stdlib.h>
#include "graph.h"

link_t *build_my_graph(void)
{
    int nbrs[8] = {42, 60012, 30012, 48, 50012, 3, 98, 8};
    link_t **link = malloc(sizeof(link_t *) * 8);

    for (int i = 0; i < 8; i++)
        link[i] = create_link(nbrs[i]);
    connect_links(link[0], link[1]);
    connect_links(link[0], link[3]);
    connect_links(link[1], link[2]);
    connect_links(link[3], link[4]);
    connect_links(link[4], link[5]);
    connect_links(link[5], link[6]);
    connect_links(link[5], link[7]);
    return link[0];
}
