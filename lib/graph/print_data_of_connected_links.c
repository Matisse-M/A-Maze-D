/*
** EPITECH PROJECT, 2023
** main
** File description:
** Minishell 1
*/

#include <stdlib.h>
#include "graph.h"
#include "../../include/my.h"

void print_data_of_connected_links(link_t *link)
{
    link_t *temp = link;

    if (link->link != NULL) {
        for (int i = 0; i < my_structlen(link->link); i++) {
            temp = temp->link[i];
            print("%d\n", temp->data);
        }
    }
}
