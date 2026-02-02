CXX		= c++
SRC		= main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98 -g3
NAME		= a.out

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
