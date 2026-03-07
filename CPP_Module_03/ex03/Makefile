NAME = main
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp   main.cpp ScavTrap.cpp DiamondTrap.cpp FragTrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all