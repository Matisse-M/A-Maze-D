/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** parser
*/

#include "../include/struct.h"

static void print_rooms_tunnels(graph_t *graph)
{
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
    }
}

int print_output(graph_t *graph)
{
    print("#number_of_robots\n");
    print("%i\n", graph->nb_robot);
    print_rooms_tunnels(graph);
    init_room(graph);
    simple_maze(graph);
    if (graph->is_way == true) {
        print("#moves\n");
        move_bots(graph);
    } else
        return 84;
    return 0;
}

int init_struct(graph_t *graph, int nb_tunel)
{
    char **dup = NULL;

    graph->read = 0;
    graph->path = NULL;
    graph->l = NULL;
    graph->len = 0;
    graph->nb_robot = my_getnbr(graph->all[0]);
    dup = dup_arr(graph->all);
    graph->room = my_arrndup(graph->all, 1, graph->tunel_pos - 1);
    graph->tunel = my_arrndup(dup, graph->tunel_pos, graph->end - 1);
    if (check_if_the_end_is_called(graph) == 84)
        return 84;
    init_robots(graph);
    if (print_output(graph) == 84)
        return 84;
    return 0;
}

int cont_tunel(graph_t *graph, int i, int nb_tunel)
{
    if (check_all(graph, i) == 84)
        return -1;
    if (i >= graph->st_tu && is_a_tunnel(i, graph->all[i], graph) == 1) {
        nb_tunel += 1;
        if (nb_tunel == 1)
            graph->tunel_pos = i;
    }
    if (i >= graph->st_tu && is_a_tunnel(i, graph->all[i], graph) == 0) {
        graph->er = i;
        return -1;
    }
    return nb_tunel;
}

static int check_coordinates_returns(graph_t *graph, int j)
{
    if (strcmp_my(graph->dup[j], "##start") != 1 &&
        strcmp_my(graph->dup[j], "##end") != 1) {
        if (check_coordinates(graph, j, graph->dup[j]) == 0) {
            graph->er = j;
            graph->is_error = 1;
            return 84;
        }
    }
    return 0;
}

static int check_name_returns(graph_t *graph, int f)
{
    if (strcmp_my(graph->all[f], "##start") != 1 &&
        strcmp_my(graph->all[f], "##end") != 1) {
        if (check_room_names(graph, f, graph->all[f]) == 0) {
            graph->er = f;
            graph->is_error = 2;
            return 84;
        }
    }
    return 0;
}

int parser(int argc, char **argv, graph_t *graph)
{
    graph->nb_tunel = 0;
    for (int f = 1; f != graph->st_tu; f++) {
        if (check_name_returns(graph, f) == 84)
            return 84;
    }
    for (int j = 0; graph->dup[j] != NULL; j++) {
        if (check_coordinates_returns(graph, j) == 84)
            return 84;
    }
    for (int i = 0; graph->all[i] != NULL; i++) {
        graph->nb_tunel = cont_tunel(graph, i, graph->nb_tunel);
        if (graph->nb_tunel == -1)
            return 84;
    }
    if (graph->nb_tunel < 1)
        return 84;
    if (init_struct(graph, graph->nb_tunel) == 84)
        return 1;
    return 0;
}

int handle_move(graph_t *graph, int argc, char **argv)
{
    int check = 0;

    graph->is_error = 0;
    graph->no_end = 0;
    graph->er_tunel[0] = -1;
    check = parser(argc, argv, graph);
    if (check == 84) {
        if (graph->no_end != -1)
            init_error(graph);
        return 84;
    }
    if (check == 1)
        return 84;
    return 0;
}
