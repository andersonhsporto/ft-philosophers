NAME	= philo

CC		= gcc

CFLAGS	= -Wall #-g #-Wextra -Werror

HEADER	= philosophers.h

SRC		= 0-philosophers.c 1-inspect.c 2-inspect_utils.c 3-ft_atoi.c 4-init.c

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	rm -rf $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
