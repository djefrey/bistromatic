##
## EPITECH PROJECT, 2020
## makefile
## File description:
## first makefile
##

SRC		=	$(wildcard *.c)
INC_DIR	=	../../include/
CFLAGS	=	-W -Wall -I$(INC_DIR)
OBJ		=	$(SRC:.c=.o)
NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all