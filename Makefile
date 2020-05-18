##
## EPITECH PROJECT, 2020
## PSU_my_ls_2019
## File description:
## Makefile
##

NAME	= my_ls

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
		./src/manage_dir.c \
		./src/table.c \
		./src/my_ls.c \
		./src/opt_l.c \
		./src/opt_l_format.c \
		./src/opt_a.c \
		./src/opt_d.c \
		./lib/my_strcat.c \
		./lib/my_sort_alpha_order.c \
		./lib/my_strcmp.c \
		./lib/my_strlen.c \
		./lib/my_strcpy.c \
		./src/opt_rec.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/my_printf/
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) lib/my_printf.a -g3

clean:
	make -C lib/my_printf/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C lib/my_printf/ fclean
	$(RM) $(NAME)

re: fclean all
