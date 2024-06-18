/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** test_lib
*/

// Function prototypes
#include "../include/my.h"
#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Test(my_getnbr, Number)
{
    cr_assert_eq(my_getnbr("42"), 42);
}

Test(my_getnbr, Zero)
{
    cr_assert_eq(my_getnbr("0"), 0);
}

Test(my_getnbr, Negative)
{
    cr_assert_eq(my_getnbr("-84"), -84);
}

Test(my_getnbr, NoNumber)
{
    cr_assert_eq(my_getnbr("Wilfried"), 0);
}

Test(my_getnbr, EmptyString)
{
    cr_assert_eq(my_getnbr(""), 0);
}

Test(my_getnbr, InsaneNumber)
{
    cr_assert_eq(my_getnbr("154875489558"), 0);
}

Test(my_getnbr, InsaneSign)
{
    cr_assert_eq(my_getnbr("+--+45"), 45);
}

Test(my_strdup, Basic)
{
    cr_assert_str_eq(my_strdup("Hello"), strdup("Hello"));
}

Test(my_strdup, Void)
{
    cr_assert_str_eq(my_strdup(""), strdup(""));
}

Test(my_strdup, Long_string)
{
    cr_assert_str_eq(my_strdup("Hello World! Welcome to the Black Parade"), strdup("Hello World! Welcome to the Black Parade"));
}

char *my_cpy(char *dest, const char *src);

Test(my_cpy, should_copy_string_correctly)
{
    char dest[20];
    const char *src = "Hello, World!";
    char *expected = "Hello, World!";
    char *result = my_cpy(dest, src);

    cr_assert_str_eq(result, expected);
}

Test(my_len, should_return_correct_length)
{
    const char *str = "Hello, World!";
    size_t expected = 13;
    size_t result = my_len(str);
    cr_assert_eq(result, expected);
}

Test(dup_arr, should_duplicate_array_of_strings)
{
    char *strings[] = {"Hello", "World", "!", NULL};
    char *expected[] = {"Hello", "World", "!", NULL};
    char **result = dup_arr(strings);
    for (int i = 0; expected[i] != NULL; i++) {
        cr_assert_str_eq(result[i], expected[i]);
    }
}

Test(my_array_to_str, should_convert_array_of_strings_to_single_string)
{
    char *strings[] = {"Hello", "World", "!", NULL};
    char *expected = "Hello World !";
    char *result = my_array_to_str(strings);
    cr_assert_str_eq(result, expected);
}

