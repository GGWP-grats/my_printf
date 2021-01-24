NAME = libftprintf.a
SRC = src/print.c src/ft_printf.c src/put_format.c src/bonus_print.c src/ll_put_format.c
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
	$(CCW) $(incl) -c $< -o $@

test: $(NAME)
	$(CCW) test.c -g $(NAME) $(incl) -o test
	./test

clean:
	@rm -rf src/*.o
	@make clean -C $(LIBFT)

$(LIBFT):
	@make -C libft

fclean: clean
	@rm -rf $(NAME) test
	@rm -rf *.dSYM

re: clean all
	@make fclean -C	$(LIBFT) 

ref: fclean

.PHONY: test re clean $(LIBFT) $(NAME) all
