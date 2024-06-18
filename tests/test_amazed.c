/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** test_amezed
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"// 

void print_error(graph_t *graph);
void handle_empty_tunel(graph_t *graph);
int init_error(graph_t *graph);
void free_func(graph_t *graph);

void redirect_stdout()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


Test(free_func, test_free_func)
{
    graph_t graph;
    graph.all = malloc(sizeof(char *) * 3);
    graph.all[0] = my_strdup("1 4 5");
    graph.all[1] = my_strdup("3 4 6");
    graph.all[2] = NULL;
    graph.room = malloc(sizeof(char *) * 3);
    graph.room[0] = my_strdup("4 5 6");
    graph.room[1] = my_strdup("6 8 7");
    graph.room[2] = NULL;
    graph.tunel = malloc(sizeof(char *) * 3);
    graph.tunel[0] = my_strdup("5-4");
    graph.tunel[1] = my_strdup("5-7");
    graph.tunel[2] = NULL;

    free_func(&graph);

}

// Test(print_error, test_print_error)
// {
//     graph_t graph;
//     graph.all = malloc(sizeof(char *) * 2);
//     graph.all[0] = strdup("ufn");
//     graph.all[1] = NULL;

//     redirect_stdout();
//     int result = getline_input(&graph);
//     cr_assert_eq(result, 84);
//     //cr_assert_stdout_eq_str("5\n#rooms\nRoom 1Room 2#tunnels\nTunnel 1Tunnel 2");
// }



// Test(init_error, test_init_error)
// {
//     graph_t graph;
//     graph.all = malloc(sizeof(char*) * 7);
//     graph.all[0] = strdup("3");
//     graph.all[1] = strdup("2 5 0\n");
//     graph.all[2] = strdup("##start\n");
//     graph.all[3] = strdup("0 1 2");
//     graph.all[4] = strdup("##end\n");
//     graph.all[5] = strdup("1 9 2\n");
//     graph.all[6] = strdup("7 5 4\n");
//     graph.all[7] = strdup("0-2\n");
//     graph.all[8] = strdup("1-fun\n");
//     graph.tunel_pos = 7;
//     graph.er = 8;

//     redirect_stdout();
//     int result = init_error(&graph);
//     cr_assert_eq(result, 84);
// }

// Test(main, test_main_with_help_option)
Test(main, test_main_with_help_option, .init = redirect_stdout)
{
    char *argv[] = {"./amazed", "-h"};
    int argc = sizeof(argv) / sizeof(argv[0]);
    int result = base(argc, argv, NULL);
    cr_assert_eq(result, 0);
}

// // Test(main, test_main_with_invalid_option)
Test(main, test_main_with_invalid_option)
{
    char *argv[] = {"./amazed", "-invalid"};
    int argc = sizeof(argv) / sizeof(argv[0]);
    int result = base(argc, argv, NULL);
    cr_assert_eq(result, 84);
}


// Test(main, test_main_with_valid_arguments)
Test(main, test_main_with_valid_arguments)
{
    char *argv[] = {"./amazed", "value1", "value2", "value3"};
    int argc = sizeof(argv) / sizeof(argv[0]);
    graph_t *graph = NULL;
    int result = base(argc, argv, NULL);
    cr_assert_eq(result, 84);
    cr_assert_null(graph);
}

// Test(helper, test_helper)
Test(helper, test_helper)
{
    redirect_stdout();
    helper();
    cr_assert_stdout_eq_str("\nThis project is a mix between a maze and linked list graphs.\n"
                            "The purpose of this propose of this maze is to have the most robot get out of it in the shortest time.\n"
                            "\nUsage:\n"
                            "\t./labgen.l value value value \n"
                            "\t./amazed < maze.txt\n");
}

// Test(shift_array, test_shift_array)
Test(shift_array, test_shift_array)
{
    char *arr[] = {"apple", "banana", "cherry", NULL};
    shift_array(arr);
    cr_assert_str_eq(arr[0], "banana");
    cr_assert_str_eq(arr[1], "cherry");
    cr_assert_null(arr[2]);
}

Test(my_arrndup, test_my_arrndup)
{
    char *arr[] = {"apple", "banana", "cherry", "date", "elderberry", NULL};
    char **result = my_arrndup(arr, 1, 3);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "banana");
    cr_assert_str_eq(result[1], "cherry");
    cr_assert_str_eq(result[2], "date");
    cr_assert_null(result[3]);
    free(result);
}

// Test(my_arrndup, test_my_arrndup)
Test(my_arrndp, test_my_arrndup)
{
    char *arr[] = {"apple", "banana", "cherry", "date", "elderberry", NULL};
    char **result = my_arrndup(arr, 1, 3);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "banana");
    cr_assert_str_eq(result[1], "cherry");
    cr_assert_str_eq(result[2], "date");
    cr_assert_null(result[3]);
    free(result);
}

// Test(my_arrndup, test_my_arrndup_with_invalid_range)
Test(my_ardup, test_my_arrndup_with_invalid_range)
{
    char *arr[] = {"apple", "banana", "cherry", "date", "elderberry", NULL};
    char **result = my_arrndup(arr, 5, 3);
    cr_assert_null(result);
}
//test remove_comment
Test(remove_comment, test_remove_comment)
{
    char line[] = "##start\n";
    int result = remove_comment(line);
    cr_assert_eq(result, 1);
}

//test remove_comment
Test(remove_commnt, test_remove_comment)
{
    char line[] = "# this is a commentt\n";
    int result = remove_comment(line);
    cr_assert_eq(result, 1);
}


// Test(check_all, test_check_all)
Test(check_all, test_check_all)
{
    graph_t graph;
    graph.all = malloc(sizeof(char*) * 5);
    graph.all[0] = "##start\n";
    graph.all[1] = "1";
    graph.all[2] = "##end\n";
    graph.all[3] = "2";
    graph.all[4] = NULL;
    graph.er = 0;
    int i = 0;
    int result = check_all(&graph, i);
    cr_assert_eq(result, 84);
    // Add assertions to check the values of the graph struct members
}

// Test(checl_all_two, test_checl_all_two)
Test(checl_all_two, test_checl_all_two)
{
    graph_t graph;
    graph.all = malloc(sizeof(char*) * 5);
    graph.all[0] = "##start\n";
    graph.all[1] = "1";
    graph.all[2] = "##end\n";
    graph.all[3] = "2";
    graph.all[4] = NULL;
    graph.er = 0;
    int i = 0;
    int result = checl_all_two(&graph, i);
    cr_assert_eq(result, 84);
    // Add assertions to check the values of the graph struct members
}

// Test(cont_tunel, test_cont_tunel)
Test(cont_tunel, test_cont_tunel)
{
    graph_t graph;
    graph.all = malloc(sizeof(char*) * 5);
    graph.all[0] = "##start\n";
    graph.all[1] = "1";
    graph.all[2] = "##end\n";
    graph.all[3] = "2";
    graph.all[4] = NULL;
    graph.er = 0;
    graph.st_tu = 0;
    int i = 0;
    int nb_tunel = 0;
    int result = cont_tunel(&graph, i, nb_tunel);
    cr_assert_eq(result, -1);
    // Add assertions to check the values of the graph struct members
}

// Test(parser, test_parser)
// Test(parser, test_nb_tunel_error)


bot_t *fill_robots(int n, int r, bot_t **begin);
// Test(fill_robots, test_fill_robots)
Test(fill_robots, test_fill_robots)
{
    bot_t *begin = NULL;
    bot_t *result = fill_robots(1, "room1", &begin);
    
    cr_assert_not_null(result);
    cr_assert_eq(result->id, 1);
    cr_assert_str_eq(result->room, "room1");
    cr_assert_null(result->current);
    cr_assert_null(result->next);
    
    // Add additional assertions if needed
}

Test(part_two_else_loop, test_case)
{
    char line[] = "This is a test # with comment";
    char *comment_pos = strchr(line, '#');
    char *end = NULL;

    int result = part_two(line, comment_pos, end);

    cr_assert_eq(result, 1, "Expected else loop to return 0");
    cr_assert_str_eq(line, "This is a test ");
}

Test(part_two_else_loop_when_comment_starts_with_space, test_case)
{
    char line[] = "This is a test #  with comment";
    char *comment_pos = strchr(line, '#');
    char *end = NULL;

    int result = part_two(line, comment_pos, end);

    cr_assert_eq(result, 1, "Expected else loop to return 0");
}

Test(part_two_else_loop_when_comment_is_at_beginning, test_case)
{
    char line[] = "#Comment at beginning";
    char *comment_pos = strchr(line, '#');
    char *end = NULL;

    int result = part_two(line, comment_pos, end);

    cr_assert_eq(result, 1, "Expected else loop to return 1");
    cr_assert_str_eq(line, "");
}

Test(part_two_else_loop_when_space_before_comment, test_case)
{
    char line[] = "This is a test   #comment";
    char *comment_pos = strchr(line, '#');
    char *end = NULL;

    int result = part_two(line, comment_pos, end);

    cr_assert_eq(result, 1, "Expected else loop to return 0");
}

// Test(init_robots, test_init_robots)
// Test(init_robots, test_init_robots)
// {
//     graph_t graph;
//     graph.nb_robot = 3;
//     graph.val_start = "2";
//     graph.bots = NULL;

//     init_robots(&graph);
//     cr_assert_not_null(graph.bots);
//     cr_assert_eq(graph.bots->id, 3);
//     cr_assert_eq(graph.bots->room, 2);
//     cr_assert_eq(graph.bots->next->id, 2);
//     cr_assert_eq(graph.bots->next->room, 2);
//     cr_assert_eq(graph.bots->next->next->id, 1);
//     cr_assert_eq(graph.bots->next->next->room, 2);
//     cr_assert_null(graph.bots->next->next->next);
// }

// Test(display_robots, test_display_robots)
// {
//     graph_t graph;
//     graph.bots = malloc(sizeof(bot_t));
//     graph.bots->id = 1;
//     graph.bots->room = 0;
//     graph.bots->next = NULL;
//     redirect_stdout();
//     display_robots(&graph);
//     cr_assert_stdout_eq_str("[1]\n");
//     free(graph.bots);
// }

Test(is_a_tunnel, test_is_a_tunnel)
{
    graph_t graph;
    int pos = 3;
    graph.dup = malloc(sizeof(char*) * 5);
    graph.dup[0] = "##start";
    graph.dup[1] = "1";
    graph.dup[2] = "##end";
    graph.dup[3] = "2";
    graph.dup[4] = NULL;

    int result = is_a_tunnel(pos, "1-2", &graph);
    cr_assert_eq(result, 1);
    // Add assertions to check the values of the graph struct members
}

Test (my_copy_null, test_isstr_null)
{
    char *str = NULL;

    int result = my_len(str);
    cr_assert_eq(result, 0);
}

// Test(remove comment, test_malloc_failure)

Test (my_comment_start, test_comment)
{
    char *line = strdup("##start");

    int result = remove_comment(line);
    cr_assert_eq(result, 0);
}

Test(remove_comment, test_else_loop)
{
    char line[] = "#This is a line with a comment at the end // Comment";
    int result = remove_comment(line);
    cr_assert_eq(result, 1);
}

void init_coordinates(graph_t *graph);
char *get_str(graph_t *graph, char *str);
int check_coordinates(graph_t *graph, int j, char *str);

Test(init_coordinates, test_init_coordinates)
{
    graph_t graph;
    graph.dup = malloc(sizeof(char*) * 5);
    graph.dup[0] = "5 1 2";
    graph.dup[1] = "1 1 2";
    graph.dup[2] = "4 1 2";
    graph.dup[3] = "2 1 2";
    graph.dup[4] = NULL;

    init_coordinates(&graph);
    cr_assert_str_eq(graph.coordinates[0], "12");
}

Test(get_str, test_get_str)
{
    graph_t graph;
    graph.dup = malloc(sizeof(char*) * 5);
    graph.dup[0] = "1 2 2";
    graph.dup[1] = "3 2 2";
    graph.dup[2] = "4 6 5";
    graph.dup[3] = "2 2 3";
    graph.dup[4] = NULL;

    char *result = get_str(&graph, "1 2 2");
    cr_assert_str_eq(result, "22");
    free(graph.dup);
    free(result);
}

Test(check_coordinates, test_check_coordinates)
{
    graph_t graph;
    graph.coordinates = malloc(sizeof(char*) * 4);
    graph.coordinates[0] = "2 3 4";
    graph.coordinates[1] = "45";
    graph.coordinates[2] = NULL;

    int result = check_coordinates(&graph, 1, "3 3 4");
    cr_assert_eq(result, 1);

    result = check_coordinates(&graph, 1, "3 4 5");
    cr_assert_eq(result, 0);
    cr_assert_str_eq(graph.coordinates[1], "45");

}

Test(check_coordinates, test_check_coordinates_not_num)
{
    graph_t graph;
    graph.coordinates = malloc(sizeof(char*) * 4);
    graph.coordinates[0] = "2 3 4";
    graph.coordinates[1] = "4 5 4";
    graph.coordinates[2] = NULL;

    int result  = check_coordinates(&graph, 1, "4 6 SERS");
    cr_assert_eq(result, 0);
}


// #include "your_graph_struct.h" // Replace with the actual header file containing the graph_t struct

// Redirect print calls to the mock_print function
// void redirect_print() {
//     cr_redirect_stdout();
//     cr_redirect_stderr();
//     cr_set_log_file(NULL);
//     cr_set_logger(mock_print);
// }

// Test handle_empty_same_coordinates function
Test(handle_empty_same_coordinates, test_handle_empty_same_coordinates, .init = redirect_stdout)
{
    graph_t graph;
    graph.nb_robot = 1;
    graph.er = 3;
    graph.dup = malloc(sizeof(char*) * 4);
    graph.dup[0] = "room1";
    graph.dup[1] = "room2";
    graph.dup[2] = "room3";
    graph.dup[3] = NULL;

    handle_empty_same_coordinates(&graph);

    cr_assert_stdout_eq_str("#number_of_robots\n1\n#rooms\nroom1\nroom2\nroom3\n");

    free(graph.dup);
}
