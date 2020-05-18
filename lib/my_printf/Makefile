##
## EPITECH PROJECT, 2020
## PSU_my_ls_2019
## File description:
## Makefile
##

NAME	= ../my_printf.a

CC	= gcc

RM	= rm -f

SRCS	= ./my_printf.c \
	  ./my_put_nbr.c \
	  ./my_put_nbrr.c \
	  ./my_write.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
