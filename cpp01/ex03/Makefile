SRCS = main.cpp Weapon.cpp  HumanA.cpp  HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = violence

CC = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) HumanA.hpp HumanB.hpp Weapon.hpp

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all