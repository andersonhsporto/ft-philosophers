NAME	= philo

CC		= gcc

CFLAGS	= -Wall -g #-Wextra -Werror

HEADER	= philosophers.h

SRC		= 	0-philosophers.c \
			1.0-inspect.c	1.1-inspect_utils.c \
			2.0-init.c		2.1-linked_list.c \
			3.0-threads.c	3.1-threads_time.c	3.2-threads_routine.c

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	rm -rf $(NAME)
	$(CC) $(CFLAGS) -pthread $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

p: all
	./philo 2 1 1 1