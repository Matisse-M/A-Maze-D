/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** moves.c
*/

#include <stdbool.h>
#include "../include/struct.h"

int no_prev(bot_t **data, int id)
{
    bot_t **list = data;
    bot_t *temp;

    if ((*list)->id == id) {
        temp = *list;
        *list = (*list)->next;
        free(temp);
        return (0);
    }
    return (1);
}

int del_node(bot_t **bot, int id)
{
    bot_t **list = bot;
    bot_t *current = *list;
    bot_t *previous = NULL;

    while (current->id != id) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    return (0);
}

bot_t *fill_robots(int n, char *str, bot_t **begin)
{
    bot_t *bot = malloc(sizeof(bot_t));

    bot->id = n;
    bot->room = my_strdup(str);
    bot->current = NULL;
    bot->next = *begin;
    return bot;
}

void init_robots(graph_t *graph)
{
    graph->bots = NULL;
    for (int i = graph->nb_robot; i > 0; i--)
        graph->bots = fill_robots(i, graph->val_start, &graph->bots);
}

static room_t *get_correct_room(graph_t *graph, room_t **path)
{
    room_t *current = *path;

    while (current != NULL) {
        if (strcmp_my(current->str, graph->bots->room) == 1)
            return current;
        current = current->next;
    }
    return *path;
}

static void get_node(room_t *rooms, graph_t *graph, int *y)
{
    int temp = rooms->id;

    *y = my_structlen2(rooms->link);
    for (int j = 0; rooms->link[j] != NULL; j++) {
        if (rooms->link[j]->id < temp && rooms->link[j]->empty) {
            temp = rooms->link[j]->id;
            *y = j;
        }
    }
    temp = rooms->id;
    for (int j = 0; rooms->link[j] != NULL &&
        *y == my_structlen2(rooms->link); j++) {
        if (rooms->link[j]->id <= temp && rooms->link[j]->empty &&
            rooms->link[j]->id < graph->nb_robot) {
            temp = rooms->link[j]->id;
            *y = j;
        }
    }
}

static void print_and_increase(int *i, graph_t *graph, int x)
{
    if (x > 0)
        print(" ");
    print("P%d-%s", graph->bots->id, graph->tempo->str);
    if (strcmp_my(graph->bots->room, graph->val_end) == 1) {
        *i += 1;
        graph->nb_robot -= 1;
        if (no_prev(&graph->first_bot, graph->bots->id) == 1)
            del_node(&graph->first_bot, graph->bots->id);
        graph->tempo->empty = true;
    }
}

static void apply_changes(graph_t *graph, int y, int x, int *i)
{
    if (y < my_structlen2(graph->tempo->link)) {
        if (graph->tempo->link[y]->id <= graph->tempo->id) {
            graph->tempo = graph->tempo->link[y];
            graph->bots->current->empty = true;
            graph->bots->current = graph->tempo;
            graph->bots->room = my_strdup(graph->tempo->str);
            graph->tempo->empty = false;
            print_and_increase(i, graph, x);
        }
    }
}

static void execute_bots(graph_t *graph, int *i, room_t *begin)
{
    int x = 0;
    int y = 0;

    while (graph->bots != NULL) {
        if (graph->bots->current == NULL)
            graph->bots->current = begin;
        graph->tempo = get_correct_room(graph, &begin);
        get_node(graph->tempo, graph, &y);
        apply_changes(graph, y, x, i);
        graph->path = begin;
        graph->bots = graph->bots->next;
        x++;
    }
}

void move_bots(graph_t *graph)
{
    room_t *begin = graph->path;

    graph->first_bot = graph->bots;
    for (int i = 0; graph->bots != NULL;) {
        execute_bots(graph, &i, begin);
        print("\n");
        graph->bots = graph->first_bot;
    }
}
