/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** no_end_tunel
*/

#include "../include/struct.h"

void no_end_connedt(graph_t *graph)
{
    print("#number_of_robots\n");
    print("%i\n", graph->nb_robot);
    print("#rooms\n");
    for (int i = 0; graph->room[i] != NULL; i++) {
        if (graph->room[i][0] != '#' ||
            strcmp_my(graph->room[i], "##start") == 1 ||
            strcmp_my(graph->room[i], "##end") == 1)
            print("%s\n", graph->room[i]);
    }
    print("#tunnels\n");
    for (int j = 0; graph->tunel[j] != NULL; j++) {
        if (graph->tunel[j][0] != '#')
            print("%s\n", graph->tunel[j]);
        if (graph->er_tunel[0] == j)
            print("Error on of the tunel isn't a known room\n");
    }
}

static char **init_tunels_check(graph_t *grahp)
{
    char *str1 = NULL;
    char **array = NULL;
    char **temp = NULL;
    int i = 0;
    int f = 0;

    for (; grahp->tunel[i] != NULL; i++) {
        array = my_realloc_array(array, 3);
        str1 = my_strdup(grahp->tunel[i]);
        temp = my_str_to_word_array(str1);
        array[f] = my_strdup(temp[0]);
        f++;
        array[f] = my_strdup(temp[1]);
        f++;
        array[f] = NULL;
    }
    array[f] = NULL;
    return array;
}

int check_if_the_end_is_called(graph_t *graph)
{
    char **tunels = init_tunels_check(graph);

    for (int i = 0; tunels[i] != NULL; i++) {
        if (strcmp_my(tunels[i], graph->val_end) == 1)
            return 1;
    }
    no_end_connedt(graph);
    graph->no_end = -1;
    return 84;
}
