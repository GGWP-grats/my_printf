NAME = printf.a

OBJ = $(SRC:.c=.o)
CCW = gcc -Wall -Wextra -Werror -g 

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CCW) $(OBJ) -o gnl

f: $(LIB) $(OBJ)
	$(CCW) -fsanitize=address -fstack-protector $(OBJ) -o gnl

%.o: %.c
	$(CCW) $(BUFFER_SIZE) -c $< -o $@
clean:
	@rm -rf *.o

libft:
	make -C libft/
fclean: clean
	@rm -rf $(NAME)

re: fclean all

ref: fclean f
.PHONY: b re clean clean libft.a $(NAME) all
