NAME = main
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongCat.cpp WrongAnimal.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all