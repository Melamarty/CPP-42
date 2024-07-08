SRCS = main.cpp Fixed.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = fixed

CC = clang++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) Fixed.hpp

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all