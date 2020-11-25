NAME=libasm.a

BIN=libasm
SRC=libasm.s

OBJ=libasm.o
FLAGS=-Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	nasm -f macho64 $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	gcc $(FLAGS) -arch x86_64 main.c $(NAME) -o $(BIN) -fno-pie

clean:
	rm -rf $(OBJ)
	rm -rf test1 test2

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BIN)

re: fclean all