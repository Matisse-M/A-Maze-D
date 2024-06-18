/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** my_cpy
*/
#include "my.h"
#include <stdlib.h>
#include <string.h>


char *my_cpy(char *dest, const char *src)
{
    char *temp = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return temp;
}

size_t my_len(const char *str)
{
    size_t length = 0;

    if (str == NULL) {
        return 0;
    }
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
