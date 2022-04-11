_SRCS = main.c load.c init.c utils.c 
_BONUS = 

SRCS = $(patsubst %.c, src/%.c, $(_SRCS))
OBJS = $(patsubst %.c, bin/%.o, $(_SRCS))

BONUS = $(patsubst %.c, src/%.c, $(_BONUS))
OBJS_BONUS = $(patsubst %.c, bin/%.o, $(_BONUS))

INCS = -I./inc -I./libft -I./mlx_linux
LIBS = -L./libft -lft -L./mlx_linux -lmlx_Linux -lXext -lX11 -lz -lm

NAME = bin/fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

libft/libft.a:
	$(MAKE) bonus -C libft/ libft.a

mlx_linux/libmlx_Linux.a:
	$(MAKE) -C mlx_linux/

$(NAME): $(OBJS) libft/libft.a mlx_linux/libmlx_Linux.a
	cc $(CFLAGS) $(INCS) $^ -o $@ $(LIBS)
bonus: $(OBJS_BONUS) libft/libft.a mlx_linux/libmlx_Linux.a
	cc $(CFLAGS) $(INCS) $^ -o $(NAME) $(LIBS)

bin/%.o: src/%.c
	mkdir -p bin
	cc $(CFLAGS) $(INCS) -c $< -o $@

check-norme:
	norminette src inc libft

clean:
	rm -f ${OBJS} ${OBJS_BONUS}
	$(MAKE) fclean -C libft/
	$(MAKE) clean -C mlx_linux/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all check-norme bonus clean fclean re
