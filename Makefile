NAME = libftprintf.a
SRC = src/print.c src/ft_printf.c src/put_format.c src/bonus_print.c
OBJ = $(SRC:.c=.o)
CCW = gcc -Wall -Wextra -Werror -g 
LIBFT = libft/
incl = -I include/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) include/ft_printf.h
	ar rc $(NAME) $(OBJ) libft/*.o

bonus:
	all

%.o: %.c
	$(CCW) $(incl) -g -c $< -o $@

test: $(NAME)
	$(CCW) test.c $(NAME) $(incl) -o test
	./test

clean:
	@rm -rf src/*.o
	@make clean -C $(LIBFT)

$(LIBFT):
	@make -C libft

fclean: clean
	@make fclean -C	$(LIBFT) 
	@rm -rf $(NAME) test

re: clean all

ref: fclean

.PHONY: test re clean $(LIBFT) $(NAME) all
