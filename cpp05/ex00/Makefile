SRCS = main.cpp Bureaucrat.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = Bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all