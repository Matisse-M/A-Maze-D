/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** my_arrndup
*/

#include "../include/struct.h"

char **my_arrndup(char **arr, int start, int end)
{
    int length = 0;
    char **result = NULL;

    if (start < 0 || end < start)
        return NULL;
    length = end - start + 1;
    result = malloc((length + 1) * sizeof(char *));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < length; i++) {
        result[i] = my_strdup(arr[start + i]);
        if (result[i] == NULL)
            return NULL;
    }
    result[length] = NULL;
    return result;
}
