NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L. -lXext -L. -lX11

RM = rm -f

SRC =	src/gameplay.c		\
		src/graphical.c		\
		src/movements.c		\
		src/so_long.c		\
		src/utils.c			\
		src/valid_argv.c	\
		src/valid_map.c		\
		src/valid_path.c	\

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
MLIBX = ./minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C ft_printf
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLIBX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft
	@make clean -C ./ft_printf
	@make clean -C ./minilibx-linux
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./ft_printf
	@make clean -C ./minilibx-linux
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re