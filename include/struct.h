/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** struct
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include "my.h"
#include "graph.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct room_s {
    bool empty;
    int id;
    char *str;
    struct room_s **link;
    struct room_s *next;
    struct room_s *prev;
} room_t;

typedef struct bot_s {
    int id;
    char *room;
    struct room_s *current;
    struct bot_s *next;
} bot_t;

typedef struct graph_s {
    char *l;
    size_t len;
    ssize_t read;
    int nb_robot;
    char **room;
    char **tunel;
    char **name_room;
    char **coordinates;
    int is_error;
    char **all;
    char **error;
    int er;
    size_t cur_size;
    size_t end_size;
    int tunel_pos;
    int nb_start;
    int nb_end;
    char *coor_first;
    int nb_tunel;
    int no_end;
    int was_start;
    int er_tunel[2];
    int end;
    char **dup;
    char *val_start;
    char *val_end;
    int st_tu;
    room_t *rooms;
    bot_t *bots;
    room_t *path;
    room_t *tempo;
    bool is_way;
    bot_t *first_bot;
} graph_t;

// parser function
int fill_arr(int argc, char **argv, graph_t *graph);
void helper(void);
int is_a_tunnel(int pos, char *line, graph_t *graph);
char *my_array_to_str(char **strings);
char **dup_arr(char **strings);
int handle_move(graph_t *graph, int argc, char **argv);

//lib like function
void shift_array(char **arr);
char **my_arrndup(char **arr, int start, int end);
int my_str_num(char const *str);
void free_func(graph_t *graph);
void init_robots(graph_t *graph);
void display_robots(graph_t *graph);
void init_room(graph_t *graph);
void print_my_graph_data2(room_t *graph);
int remove_comment(char *line);
void print_error(graph_t *graph);
void handle_empty_tunel(graph_t *graph);
int init_error(graph_t *graph);
void init_room(graph_t *graph);
int my_isnum(char const *str);
int myis_num(char const *str);

char *my_cpy(char *dest, const char *src);
size_t my_len(const char *str);
char **dup_it(char **dup_str, int *i);
char **dup_arr(char **strings);
void fil_str(int num_str, int cur_pos, char **strings, char *result);
char *my_array_to_str(char **strings);
int getline_input(graph_t *graph);
int base(int argc, char **argv, graph_t *graph);
int checl_all_two(graph_t *graph, int i);
int check_all(graph_t *graph, int i);
int cont_tunel(graph_t *graph, int i, int nb_tunel);
int parser(int argc, char **argv, graph_t *graph);
int handle_move(graph_t *graph, int argc, char **argv);
int init_struct(graph_t *graph, int nb_tunel);
void move_bots(graph_t *graph);
void simple_maze(graph_t *graph);
void init_ids(graph_t *graph);
int my_structlen2(room_t **link);
room_t *find_room(void *data, char *id);
int check_coordinates(graph_t *graph, int i, char *str);
int init_coordinates(graph_t *graph);
void handle_empty_same_coordinates(graph_t *graph);
void init_room_names(graph_t *graph);
int check_room_names(graph_t *graph, int j, char *str);
int check_if_the_end_is_called(graph_t *graph);
int part_two(char *line, char *comment_pos, char *end);
void stop_empty_line(graph_t *graph);
void print_fail(graph_t *graph);
void find_if_error(graph_t *graph, int i);

#endif /* !STRUCT_H_ */
