NAME = containers
CC = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address
SRC = main.cpp 
all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
fclean: 
	rm -f $(NAME)
re: fclean all