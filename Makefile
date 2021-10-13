SRCS= checks.c commands1.c commands2.c fill.c opers.c push_swap.c \
	sort_logic.c sort.c sorted.c utilts.c optim.c str.c sort_logic_2.c \
	sort_2.c optim_rrara.c optim_rrbrb.c optim_ssa.c

CC=		gcc

NAME=		push_swap

CFLAGS +=

CFLAGS +=	-I.

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./printf
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) libft/libft.a printf/printf.a

clean:
	cd printf && $(MAKE) clean
	cd libft && $(MAKE) clean
	rm -rvf $(OBJS)

fclean:		clean
	cd printf && $(MAKE) fclean
	cd libft && $(MAKE) fclean
	rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re