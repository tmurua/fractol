NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

MINILIBX = ./minilibx-linux
LIBFT = ./libft/libft.a

SRC = main.c window_init.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	echo "libft compiled"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lm -lmlx -lXext -lX11
	echo "$(NAME) generated"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	echo "object files deleted"

fclean: clean
	rm -f $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
