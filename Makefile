NAME = minishell

SRC = main.c\
		builtins/commands.c\
		builtins/env.c\
		builtins/pwd.c\
		finding_commands.c\


OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror
# 033 is a esc in octal ascii, 0 sets all the text attributes to 0 and 32 is green

COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m

LIBFT = -L${LIBFTPATH} -lft
LIBFTPATH = libft

$(NAME): $(OBJ)
	@ cd $(LIBFTPATH) && make all
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)  -lreadline -lncurses
	@ echo "$(COLOUR_GREEN)compiled $(words $(OBJ)) files $(COLOUR_END)"

all: $(NAME)

clean:
	@ rm -rf $(OBJ)
	@make fclean -C $(LIBFTPATH)
	@ echo "$(COLOUR_GREEN)Cleaned all 'o' files successfully$(COLOUR_END)"

fclean: clean
	@ rm -rf $(NAME)
	@ echo "$(COLOUR_GREEN)Cleaned Program name successfully$(COLOUR_END)"


re: fclean $(NAME)