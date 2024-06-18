/*
** EPITECH PROJECT, 2023
** my
** File description:
** CPool lib
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#pragma once

typedef struct link_s {
    int data;
    struct link_s **link;
} link_t;

// linked list function
link_t *create_link(int data);
void print_link(link_t *link);
void connect_links(link_t *link1, link_t *link2);
void print_data_of_connected_links(link_t *link);
link_t *build_my_graph(void);
void print_my_graph_data(link_t *graph);
int my_structlen(link_t **link);
link_t **my_realloc_struct(link_t **link, int size);
