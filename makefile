NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = main.c list.c parsing.c opiratoin.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c  $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
