NAME = fractol

SRC = full_set_test.c sets.c math.c input_handling.c lib_utils.c mandelbrot.c

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_A = libft/libft.a

MLX_A = mlx_linux/libmlx_Linux.a

all: makelibft makemlx $(NAME)

makelibft:
	make -C libft

makemlx:
	make -C mlx_linux

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	${CC} $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) -lXext -lX11 -lm -lz -o $(NAME) 

# -L mlx_test -I mlx_test

%.o:%.c Makefile fractol.h
	${CC} $(CFLAGS) -c $< -o $@

# -Imlx_linux/mlx.h

clean:
	rm -rf $(OBJS)
	make clean -C libft
	make clean -C mlx_linux

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re makelibft
