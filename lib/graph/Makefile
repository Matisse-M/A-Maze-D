##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC		=	create_link.c 						\
			print_link.c 						\
			connect_links.c 					\
			print_data_of_connected_links.c 	\
			build_my_graph.c 					\
			print_my_graph_data.c				\
			structlen.c 						\
			realloc_struct.c

OBJ 	= 	$(SRC:.c=.o)

NAME	= 	libgraph.a

CC 		= 	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		cp graph.h ../../include
		@$(AR) rc $(NAME) $(OBJ)
		cp $(NAME) ../../
		@echo -e "\e[1;36m{ libmy.a ready and my.h duplicated !! }\e[00;37m"

clean:
		@rm -f $(OBJ)
		@rm -f *~
		@echo -e "\e[1;33m[ Useless files have been deleted ]\e[00;37m"

fclean: clean
		$(RM) $(NAME)
		@echo -e "\e[1;33m[ libmy.a has been deleted ]\e[00;37m"

re: fclean all
