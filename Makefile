NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c  ls_functions.c libft/split_function.c libft/libft_fun.c check_nbrs.c check_doubles.c \
		printf/ft_hex.c printf/ft_printf.c printf/ft_putadress.c printf/ft_Upphex.c\
		printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putstr.c printf/ft_putunsigned.c\
		check_overflow.c libft/libft2.c actions/sa_sb_ss.c actions/pa_pb.c gnl/get_next_line_utils.c\
		actions/ra_rb_rr.c  actions/rra_rrb_rrr.c sorting/sort_three.c sorting/sort_five.c\
		sorting/sort_utils.c sorting/stack_sort.c sorting/set_cost_to_push.c\
		sorting/stack_sort_utils2.c push_swap_utils.c
BSRCS = bonus/checker.c push_swap_utils.c ls_functions.c libft/split_function.c \
		libft/libft_fun.c check_nbrs.c check_doubles.c gnl/get_next_line_utils.c\
		printf/ft_hex.c printf/ft_printf.c printf/ft_putadress.c printf/ft_Upphex.c\
		printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putstr.c printf/ft_putunsigned.c\
		check_overflow.c libft/libft2.c actions/sa_sb_ss.c actions/pa_pb.c\
		actions/ra_rb_rr.c  actions/rra_rrb_rrr.c gnl/get_next_line.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus : $(BNAME)

$(BNAME) : $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS)


clean :
	rm -rf $(OBJS) $(BOBJS)

fclean : clean
	rm -rf $(NAME) $(BNAME)

re : fclean all

.PHONY: all clean fclean re 