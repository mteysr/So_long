NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OTHERS = minilibx/libmlx.a
SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c libft_fon.c libft_fonc.c so_long_main.c control.c control2.c mlx_fonc.c pres_fon.c so_long_utils.c control3.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Iincludes -framework OpenGL -framework AppKit -o $(NAME) $(OTHERS)


clean :
	rm -f ./libft_fon.o libft_fonc.o so_long_main.o control.o control2.o mlx_fonc.o pres_fon.o so_long_utils.o control3.o
	rm -f ./gnl/get_next_line_utils.o

fclean : clean
	rm -rf $(NAME)
	rm -rf gnl/get_next_line.o

re : fclean all

.PHONY : all fclean clean re
