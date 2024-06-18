/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** test_init-room
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

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
        strcmp(room1->str, room2->str) == 1)
        return 0;
    room1->link = my_realloc_struct2(room1->link, 1);
    room2->link = my_realloc_struct2(room2->link, 1);
    room2->link[my_structlen2(room2->link)] = room1;
    room1->link[my_structlen2(room1->link)] = temp;
    return 0;
}

Test(my_structlen2, test_my_structlen2_null)
{
    room_t **link = NULL;
    int result = my_structlen2(link);
    cr_assert_eq(result, 0);
}

Test(my_structlen2, test_my_structlen2_empty)
{
    room_t *link[] = {NULL};
    int result = my_structlen2(link);
    cr_assert_eq(result, 0);
}

Test(my_structlen2, test_my_structlen2_non_empty)
{
    room_t *room1 = malloc(sizeof(room_t));
    room_t *room2 = malloc(sizeof(room_t));
    room_t *room3 = malloc(sizeof(room_t));
    room_t *link[] = {room1, room2, room3, NULL};
    int result = my_structlen2(link);
    cr_assert_eq(result, 3);
}

// Tests for my_realloc_struct2 function
Test(my_realloc_struct2, test_my_realloc_struct2_null)
{
    room_t **link = NULL;
    int size = 5;
    room_t **result = my_realloc_struct2(link, size);
    cr_assert_not_null(result);
    free(result);
}

Test(my_realloc_struct2, test_my_realloc_struct2_empty)
{
    room_t *link[] = {NULL};
    int size = 5;
    room_t **result = my_realloc_struct2(link, size);
    cr_assert_not_null(result);
    free(result);
}

Test(my_realloc_struct2, test_my_realloc_struct2_non_empty)
{
    room_t *room1 = malloc(sizeof(room_t));
    room_t *room2 = malloc(sizeof(room_t));
    room_t *room3 = malloc(sizeof(room_t));
    room_t *link[] = {room1, room2, room3, NULL};
    int size = 5;
    room_t **result = my_realloc_struct2(link, size);
    cr_assert_not_null(result);
    cr_assert_eq(my_structlen2(result), my_structlen2(link));
    free(result);
}

Test(connect_links2, test_connect_links2_invalid)
{
    room_t *room1 = malloc(sizeof(room_t));
    room_t *room2 = malloc(sizeof(room_t));
    room1->str = strdup("room1");
    room2->str = strdup("room2");
    int result = connect_links2(room1, NULL);
    cr_assert_eq(result, 0);
}

// Tests for find_room function
Test(find_room, test_find_room_valid)
{
    room_t *room1 = malloc(sizeof(room_t));
    room_t *room2 = malloc(sizeof(room_t));
    room_t *room3 = malloc(sizeof(room_t));
    room1->str = strdup("room1");
    room2->str = strdup("room2");
    room3->str = strdup("room3");
    room1->next = room2;
    room2->next = room3;
    room3->next = NULL;
    room_t *data = room1;
    room_t *result = find_room(&data, "room2");
    cr_assert_eq(result, room2);
}

Test(find_room, test_find_room_invalid)
{
    room_t *room1 = malloc(sizeof(room_t));
    room_t *room2 = malloc(sizeof(room_t));
    room_t *room3 = malloc(sizeof(room_t));
    room1->str = strdup("room1");
    room2->str = strdup("room2");
    room3->str = strdup("room3");
    room1->next = room2;
    room2->next = room3;
    room3->next = NULL;
    room_t *data = room1;
    room_t *result = find_room(&data, "room4");
    cr_assert_null(result);
}

Test(create_room, test_create_room)
{
    room_t *elem = NULL;
    char *str = "room1";
    room_t *result = create_room(str, &elem);
    cr_assert_not_null(result);
    cr_assert_str_eq(result->str, str);
    cr_assert_null(result->link);
    cr_assert_null(result->prev);
    cr_assert_null(result->next);
}
