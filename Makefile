##
## EPITECH PROJECT, 2023
## my_organize
## File description:
## my_organize
##

CC	=	gcc

NAME	=	amazed

UNIT_TEST	= test

CFLAGS	=	-Wshadow -Werror -Wall -I./include

CRITFLAG	=	tests/test_lib.c tests/test_amazed.c tests/test_init-room.c

LIBS	=	--coverage -lcriterion -L./ -lmy -L./ -lgraph

TEST_LIBS	=	-I ./include

SRC		=   main.c			\
			base.c			\
			src/helper.c	\
			src/parser.c	\
			src/is_a_tunnel.c	\
			src/my_array_to_str.c	\
			src/shift_arr.c		\
			src/my_arrndup.c	\
			src/free_func.c		\
			src/init_room.c		\
			src/remove_comment.c	\
			src/init_error.c		\
			src/init_parser.c		\
			src/my_cpy.c			\
			src/check_all.c			\
			src/moves.c				\
			src/dijkstra.c			\
			src/check_coordinates.c	\
			src/no_end_tunel.c		\
			src/stop_empty_line.c	\
			src/find_errors.c

SRCTEST	= 	base.c			\
			src/helper.c	\
			src/parser.c	\
			src/is_a_tunnel.c	\
			src/my_array_to_str.c	\
			src/shift_arr.c		\
			src/my_arrndup.c	\
			src/free_func.c		\
			src/init_room.c		\
			src/remove_comment.c	\
			src/init_error.c		\
			src/init_parser.c		\
			src/my_cpy.c			\
			src/check_all.c			\
			src/moves.c				\
			src/dijkstra.c			\
			src/check_coordinates.c	\
			src/no_end_tunel.c		\
			src/stop_empty_line.c	\
			src/find_errors.c

OBJ		=	$(SRC:.c=.o)

all:	libmy libgraph $(NAME)

$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)
			@echo -e "\e[1;32m{ Makefile is ready }\e[00;37m"
			@echo -e "\e[1;36m{ Binary is ready }\e[00;37m"

$(UNIT_TEST): libmy libgraph
			$(CC) -o $(UNIT_TEST) $(SRCTEST) $(CRITFLAG) $(LIBS) $(TEST_LIBS)

tests_run:	$(UNIT_TEST)
			@./$(UNIT_TEST)
			@gcovr --exclude tests/

.PHONY: libmy

libmy:
	$(MAKE) -C lib/my

libgraph:
	$(MAKE) -C lib/graph

norm:
	@make clean
	@make fclean
	@coding-style . .
	@cat coding-style-reports.log

clean:
			$(MAKE) -C lib/my clean
			$(MAKE) -C lib/graph clean
			@rm -f $(OBJ)
			@rm -f *.gc*
			@rm -f coding-style-reports.log
			@rm -f *~
			@rm -f *.gcda
			@rm -f *.gcno
			@rm -f libmy.a

fclean:	clean
			$(MAKE) -C lib/my fclean
			$(MAKE) -C lib/graph fclean
			@rm -f $(NAME)
			@rm -f $(UNIT_TEST)
			@echo -e "\e[1;33m{ REPOSITORIE as been cleaned }\e[00;37m"
			@rm -f libmy.a
			@rm -f libgraph.a
			@rm -f *.cor

re:	fclean all
