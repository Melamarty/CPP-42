
SRCS = methods.c main.c

OBJS = $(SRCS:.c=.o)

NAME = account

CFLAFGS = -Wextra -Werror -Wall -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	clang++ $(CFLAFGS) $(OBJS) -o $(NAME)

%.o : %.c
	clang++ $(CFLAFGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all