NAME = minishell

SRC =

OBJ =

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean

re: fclean $(NAME)