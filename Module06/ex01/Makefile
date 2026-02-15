CXX      = c++
SRC      = main.cpp Data.cpp Serializer.cpp
OBJ      = $(SRC:%.c=%.o)
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
NAME     = Serializer

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
