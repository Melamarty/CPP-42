CFLAFGS = -Wextra -Werror -Wall -std=c++98
NAME = phonebook
SRCS = phonebook.cpp methods.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(CFLAFGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	clang++ $(CFLAFGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all