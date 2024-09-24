NAME = fractol

CC = cc
CFLAGS = -Wall - Wextra -Werror

SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm -lmlx -lXext - lX11
	echo "$(NAME) generated"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	echo "object files deleted"

fclean: clean
	rm -f $(NAME)
	echo "$(NAME) and object files deleted"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
