NAME = containers
CC = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g3
SRC = main.cpp 
all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
fclean: 
	rm -f $(NAME)
re: fclean all