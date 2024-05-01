SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = brain

CC = c++

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all