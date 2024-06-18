/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** init_room
*/

#include "../include/struct.h"

int my_structlen2(room_t **link)
{
    int size = 0;

    if (link == NULL)
        return 0;
    for (int i = 0; link[i] != NULL; i++)
        size++;
    return size;
}

static room_t **my_realloc_struct2(room_t **link, int size)
{
    room_t **new = NULL;

    if (link == NULL) {
        new = malloc(sizeof(room_t *) * (size + 1));
        for (int i = 0; i <= size; i++) {
            new[i] = NULL;
        }
        return new;
    }
    new = malloc(sizeof(room_t *) * (my_structlen2(link) + size + 1));
    for (int i = 0; i < my_structlen2(link); i++)
        new[i] = link[i];
    for (int i = 0; i <= size; i++)
        new[my_structlen2(link) + i] = NULL;
    return new;
}

static int connect_links2(room_t *room1, room_t *room2)
{
    room_t *temp = room2;

    if (room1 == NULL || room2 == NULL ||
        strcmp_my(room1->str, room2->str) == 1)
        return 0;
    room1->link = my_realloc_struct2(room1->link, 1);
    room2->link = my_realloc_struct2(room2->link, 1);
    room2->link[my_structlen2(room2->link)] = room1;
    room1->link[my_structlen2(room1->link)] = temp;
    return 0;
}

room_t *find_room(void *data, char *id)
{
    room_t *room = *(room_t **)data;

    while (room != NULL) {
        if (strcmp_my(room->str, id) == 1)
            return room;
        room = room->next;
    }
    return NULL;
}

int disp_room(room_t *room, graph_t *graph)
{
    char *str = NULL;
    char **array = NULL;

    for (int j = 0; graph->tunel[j] != NULL; j++) {
        str = my_strdup(graph->tunel[j]);
        array = my_str_to_word_array(str);
        connect_links2(find_room(&room, array[0]),
            find_room(&room, array[1]));
    }
    return (0);
}

room_t *create_room(char *str, room_t **elem)
{
    room_t *room = malloc(sizeof(room_t));

    room->id = 2147483647;
    room->empty = true;
    room->str = my_strdup(str);
    room->link = NULL;
    room->next = *elem;
    room->prev = NULL;
    if (*elem != NULL)
        (*elem)->prev = room;
    return room;
}

void init_room(graph_t *graph)
{
    char *dup = NULL;
    char **id = NULL;

    graph->rooms = NULL;
    for (int i = 0; graph->room[i] != NULL; i++) {
        if (strcmp_my("##start", graph->room[i]) != 1 &&
            strcmp_my("##end", graph->room[i]) != 1) {
            id = my_str_to_word_array(graph->room[i]);
            dup = my_strdup(id[0]);
            graph->rooms = create_room(dup, &graph->rooms);
            id = NULL;
        }
    }
    disp_room(graph->rooms, graph);
}
