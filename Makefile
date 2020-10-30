##
## EPITECH PROJECT, 2020
## infinadd
## File description:
## makefile of infinadd
##

MAIN		=	main.c
SRC			=	evalexpr.c						\
				convert_base.c					\
				errors.c						\
				./infinop/infinadd.c			\
				./infinop/infinsub.c			\
				./infinop/infinmult.c			\
				./infinop/infindiv.c			\
				./infinop/infinmod.c			\
				./infinop/operations.c
NCURSES		=	./bonus/ncurses/graph_main.c	\
				./bonus/ncurses/windows.c		\
				./bonus/ncurses/print_fcts.c	\
				./bonus/ncurses/utilities.c		\
				./bonus/ncurses/inputs.c
TESTS		=	./tests/add_tests.c				\
				./tests/mult_tests.c			\
				./tests/div_tests.c				\
				./tests/mod_tests.c				\
				./tests/expr_tests.c
LIB_DIR		=	./lib/my/
INC_DIR		=	./include/
CFLAGS		+=	-g -W -Wall -I$(INC_DIR)
MAIN_OBJ	=	$(MAIN:.c=.o)
OBJ			=	$(SRC:.c=.o)
NCURSES_OBJ	=	$(NCURSES:.c=.o)
TESTS_OBJ	=	$(TESTS:.c=.o)
NAME		=	calc
NAME_NCURSES=	calc_graph
NAME_CRIT	=	calc_crit

all:	$(NAME)

$(NAME):	$(MAIN_OBJ) $(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(MAIN_OBJ) $(OBJ) -I$(INC_DIR) -L$(LIB_DIR) -lmy

ncurses: $(OBJ) $(NCURSES_OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME_NCURSES) $(OBJ) $(NCURSES_OBJ) -I$(INC_DIR) -L$(LIB_DIR) -lmy -lncurses

criterion: $(OBJ) $(TESTS_OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME_CRIT) $(TESTS_OBJ) $(OBJ) -I$(INC_DIR) -L$(LIB_DIR) -lmy -lcriterion

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ)
	rm -f $(MAIN_OBJ)
	rm -rf $(NCURSES_OBJ)
	rm -rf $(TESTS_OBJ)

fclean:	clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)
	rm -f $(NAME_NCURSES)
	rm -f $(NAME_CRIT)

re: fclean all