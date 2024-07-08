# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 04:55:06 by mel-amar          #+#    #+#              #
#    Updated: 2024/01/13 19:56:02 by mel-amar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAFGS = -Wextra -Werror -Wall -std=c++98
NAME = phonebook
SRCS = phonebook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) phonebook.hpp
	clang++ $(CFLAFGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	clang++ $(CFLAFGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all