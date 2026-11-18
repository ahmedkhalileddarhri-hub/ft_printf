NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.
AR		= ar rcs
RM		= rm -f

SRCS	= ft_printf.c \
		  parsers.c \
		  src/ft_putchar.c \
		  src/ft_putstr.c \
		  src/ft_putnbr.c \
		  src/ft_strlen.c \
		  src/print_ptr.c \
		  src/putnbr_base.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
