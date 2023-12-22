NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIB_PATH		:= ./mylib/ft_print
LIB		:= $(LIB_PATH)/libftprintf.a


HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= $(shell find ./src -iname "*.c")
SRCS	:= src/main.c src/utilis.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(LIB) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(LIB):
	@make -sC $(LIB_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIB_PATH) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx