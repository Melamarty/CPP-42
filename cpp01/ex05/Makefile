SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = Harl

CC = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) Harl.hpp

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all