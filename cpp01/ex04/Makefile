SRCS = main.cpp ft_sed.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = ft_sed

CC = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) ft_sed.hpp

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all