SRCS=  libft/libft.a printf/printf.a checks.c commands1.c commands2.c fill.c opers.c push_swap.c sort_logic.c sort.c sorted.c utilts.c optim.c str.c

CC=		gcc 

NAME=		push_swap

CFLAGS +=	
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -rvf $(OBJS)

fclean:		clean
	rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re