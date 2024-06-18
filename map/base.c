/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** base
*/

#include "include/struct.h"

int base(int argc, char **argv, graph_t *graph)
{
    if (argc > 1) {
        if (strcmp_my(argv[1], "-h") == 1 ||
            strcmp_my(argv[1], "--help") == 1) {
            helper();
            return 0;
        } else
            return 84;
    } else {
        if (fill_arr(argc, argv, graph) == 84)
            return 84;
    }
    return 0;
}
