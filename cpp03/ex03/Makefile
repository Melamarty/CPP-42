SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp  FragTrap.cpp DiamondTrap.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = DiamondTrap

CC = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all