SRCS = main.cpp ClapTrap.cpp  FragTrap.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = FragTrap

CC = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all