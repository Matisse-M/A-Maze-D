/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** check_coordinates
*/

#include "../include/struct.h"

int init_coordinates(graph_t *graph)
{
    char *str = NULL;
    char *dup = NULL;
    int i = 0;
    char **array = NULL;

    graph->coor_first = NULL;
    for (; graph->dup[i] != NULL; i++) {
        if (graph->dup[i][0] != '#')
            break;
    }
    dup = my_strdup(graph->dup[i]);
    array = my_str_to_word_array(dup);
    graph->coordinates = my_malloc(graph->coordinates, 2);
    str = my_strcat(array[1], array[2]);
    graph->coor_first = my_strdup(str);
    graph->coordinates[0] = my_strdup(str);
    if (my_isnum(str) == 0)
        return -1;
    graph->coordinates[1] = NULL;
    return 0;
}

void init_room_names(graph_t *graph)
{
    char *dup = NULL;
    int i = 1;
    char **array = NULL;

    for (; graph->all[i] != NULL; i++) {
        if (graph->all[i][0] != '#')
            break;
    }
    dup = my_strdup(graph->all[i]);
    array = my_str_to_word_array(dup);
    graph->name_room = my_malloc(graph->name_room, 2);
    graph->name_room[0] = my_strdup(array[0]);
    graph->name_room[1] = NULL;
}

char *get_str(graph_t *graph, char *str)
{
    char *str1 = my_strdup(str);
    char **array = my_str_to_word_array(str1);
    char *str2 = NULL;

    if (array[2] == NULL)
        return NULL;
    str2 = my_strcat(array[1], array[2]);
    return str2;
}

int check_coordinates(graph_t *graph, int j, char *str)
{
    int i = 1;
    char *str2 = my_strdup(str);
    char **array = NULL;
    char *string = NULL;

    for (; graph->coordinates[i] != NULL; i++) {
        string = get_str(graph, str);
        if (string == NULL)
            return 0;
        if (strcmp_my(graph->coordinates[i], string) == 1 ||
            my_isnum(string) == 0)
            return 0;
        string = NULL;
    }
    graph->coordinates = my_realloc_array(graph->coordinates, 1);
    array = my_str_to_word_array(str2);
    str2 = my_strcat(array[1], array[2]);
    graph->coordinates[i] = my_strdup(str2);
    return 1;
}

int check_room_names(graph_t *graph, int j, char *str)
{
    int i = 1;
    char *str2 = my_strdup(str);
    char **array = my_str_to_word_array(str2);

    for (; graph->name_room[i] != NULL; i++) {
        if (strcmp_my(graph->name_room[i], array[0]) == 1)
            return 0;
    }
    graph->name_room = my_realloc_array(graph->name_room, 1);
    graph->name_room[i] = my_strdup(array[0]);
    return 1;
}
