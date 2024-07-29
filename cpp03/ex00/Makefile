SRCS = main.cpp ClapTrap.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = ClapTrap

CC = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) ClapTrap.hpp

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all