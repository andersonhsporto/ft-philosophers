NAME	= philo

CC		= gcc

CFLAGS	= -Wall #-Wextra -Werror

SRC		= ft_atoi.c inspect.c inspect_utils.c philosophers.c

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
