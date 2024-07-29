SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = bsp

CC = clang++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) Fixed.hpp

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all