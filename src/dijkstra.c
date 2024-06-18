/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** dijkstra.c
*/

#include <stdbool.h>
#include "../include/struct.h"

static room_t *first_node(graph_t *graph)
{
    room_t *temp = graph->rooms;

    while (temp != NULL) {
        if (strcmp_my(temp->str, graph->val_start) == 1) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

static room_t *last_node(graph_t *graph)
{
    room_t *temp = graph->rooms;

    while (temp != NULL) {
        if (strcmp_my(temp->str, graph->val_end) == 1) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

static room_t *create_path(room_t *current, room_t **elem)
{
    room_t *room = malloc(sizeof(room_t));

    room->id = current->id;
    room->empty = true;
    room->str = my_strdup(current->str);
    room->link = current->link;
    room->next = *elem;
    return room;
}

static void dijkstra(graph_t *graph, room_t *first, room_t *last, int id)
{
    if (last == first) {
        last->id = 2147483646;
        graph->path = create_path(last, &graph->path);
        graph->is_way = true;
        return;
    }
    if (last != NULL && id < last->id) {
        last->id = id;
        graph->path = create_path(last, &graph->path);
    } else {
        return;
    }
    for (int i = 0; last->link[i] != NULL; i++)
        dijkstra(graph, first, last->link[i], id + 1);
}

void simple_maze(graph_t *graph)
{
    room_t *first = first_node(graph);
    room_t *last = last_node(graph);

    dijkstra(graph, first, last, 0);
}
