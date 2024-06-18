/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** is_a_tunnel
*/

#include "../include/struct.h"
#include <stdbool.h>

static int find_second_room(graph_t *graph, char **dup_ar, int i, char *str)
{
    char **dup1 = NULL;
    char **dup2 = NULL;
    char *str2 = NULL;
    bool stat = false;

    if (strcmp_my(dup_ar[i], "##start") != 1 &&
        strcmp_my(dup_ar[i], "##end") != 1) {
        str2 = my_strdup(dup_ar[i]);
        dup1 = my_str_to_word_array(str2);
        dup2 = my_str_to_word_array(str);
        if (dup2[1] == NULL)
            return stat;
        if (strcmp_my(dup2[1], dup1[0]) == 1) {
            stat = true;
            return 1;
        }
    }
    return stat;
}

static int find_first_room(graph_t *graph, int i, char *line)
{
    char **dup1 = NULL;
    char **dup2 = NULL;
    bool stat = false;
    char *str2 = NULL;

    str2 = my_strdup(graph->dup[i]);
    dup1 = my_str_to_word_array(str2);
    dup2 = my_str_to_word_array(line);
    if (dup2[0] == NULL)
        return stat;
    if (strcmp_my(dup2[0], dup1[0]) == 1) {
        stat = true;
        return 1;
    }
    return stat;
}

static int check_first(graph_t *graph, int pos, char *line)
{
    bool stat = false;

    for (int i = 0; graph->dup[i] != NULL; i++) {
        if (find_first_room(graph, i, line) == 1) {
            stat = true;
            return 1;
        }
    }
    if (stat == false)
        return 0;
    return 1;
}

int is_a_tunnel(int pos, char *line, graph_t *graph)
{
    char *str = my_strdup(line);
    char **dup_ar = dup_arr(graph->dup);

    if (check_first(graph, pos, str) == 0)
        return 0;
    for (int i = 0; dup_ar[i] != NULL; i++) {
        if (find_second_room(graph, dup_ar, i, str) == 1) {
            return 1;
        }
    }
    return 0;
}
