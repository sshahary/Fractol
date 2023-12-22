CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_useful.c ft_useful_2.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
LIB = ./Libft
LIBFT = $(LIB)/libft.a

all: $(NAME) clean

$(NAME): lib $(OBJ)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)
lib : 
	make -sC $(LIB)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C Libft/

re: fclean all

.PHONY: all lib clean fclean re