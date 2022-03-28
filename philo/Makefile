NAME	= philo

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

HEADER	= philosophers.h

SRC		= 	0_philosophers.c \
			1_0_inspect.c	1_1_inspect_utils.c \
			2_0_init.c		2_1_linked_list.c \
			3_0_threads.c	3_1_threads_time.c	3_2_threads_routine.c \
			3_3_threads_utils.c	\
			3_4_threads_death.c	\
			4_free.c

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
