##
## EPITECH PROJECT, 2020
## infinadd
## File description:
## makefile of infinadd
##

SRC			=	evalexpr.c				\
				./infinop/infinadd.c	\
				./infinop/infinsub.c	\
				./infinop/infinmult.c	\
				./infinop/infindiv.c	\
				./infinop/infinmod.c	\
				./infinop/operations.c
MAIN		=	main.c
TEST		=	./tests/tests.c
LIB_DIR		=	./lib/my/
INC_DIR		=	./include/
CFLAGS		+=	-g -W -Wall -I$(INC_DIR)
OBJ			=	$(SRC:.c=.o)
MAIN_OBJ	=	$(MAIN:.c=.o)
TEST_OBJ	=	$(TEST:.c=.o)
NAME		=	calc
NAME_CRIT	=	calc_crit

all:	$(NAME)

$(NAME):	$(MAIN_OBJ) $(OBJ) 
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(MAIN_OBJ) $(OBJ) -I$(INC_DIR) -L$(LIB_DIR) -lmy

criterion: $(OBJ) $(TEST_OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME_CRIT) $(TEST_OBJ) $(OBJ) -I$(INC_DIR) -L$(LIB_DIR) -lmy -lcriterion

clean: $(OBJ) $(MAIN_OBJ)
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ)
	rm -f $(MAIN_OBJ)

fclean:	clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)
	rm -f $(NAME_CRIT)

re: fclean all