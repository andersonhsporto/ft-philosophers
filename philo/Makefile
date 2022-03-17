NAME	= philo

CC		= gcc

CFLAGS	= -Wall #-Wextra -Werror

SRC		= philosophers.c

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

.PHONY: all bonus clean fclean re
