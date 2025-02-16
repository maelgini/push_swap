NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	src/main.c\
		src/index.c\
		src/op_rot.c\
		src/op_rrot.c\
		src/op_swap.c\
		src/op_push.c\
		src/quick_sort.c\
		src/sort_handler.c\
		src/sort_utils.c\
		src/utils.c\
		libft/libft.a\

$(NAME) :
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus :
	make bonus -C libft
	gcc $(CFLAGS) -o checker