CXX      = c++
SRC      = main.cpp ScalarConverter.cpp printInt.cpp printChar.cpp printFloat.cpp printDouble.cpp detectType.cpp
OBJ      = $(SRC:%.c=%.o)
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
NAME     = Converter

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
