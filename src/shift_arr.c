/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** shift_arr
*/

#include <stdlib.h>

void shift_array(char **arr)
{
    int i;

    for (i = 0; arr[i] != NULL; i++) {
        arr[i] = arr[i + 1];
    }
}
