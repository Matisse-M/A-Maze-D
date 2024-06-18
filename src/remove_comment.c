/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** remove_comment
*/

#include "../include/struct.h"

int part_two(char *line, char *comment_pos, char *end)
{
    if (comment_pos == line || comment_pos[-1] == ' ') {
        *comment_pos = '\0';
        return 1;
    } else {
        *comment_pos = '\0';
        end = comment_pos - 1;
        while (end >= line && *end == ' ') {
            *end = '\0';
            end--;
        }
    }
    return 0;
}

int remove_comment(char *line)
{
    char *dup = my_strdup(line);
    char *comment_pos = my_strstr(line, "#");
    char *end = NULL;

    if (dup[0] == '#')
        return 0;
    if (comment_pos != NULL && strcmp_my("##end", line) != 1 &&
        strcmp_my("##start", line) != 1) {
        if (part_two(line, comment_pos, end) == 1)
            return 1;
    }
    return 0;
}
