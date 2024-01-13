# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:04:13 by mel-amar          #+#    #+#              #
#    Updated: 2024/01/13 05:16:04 by mel-amar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = account

CFLAFGS = -Wextra -Werror -Wall -std=c++98

all : $(NAME) Account.hpp

$(NAME) : $(OBJS)
	clang++ $(CFLAFGS) $(OBJS) -o $(NAME)

%.o : %.c Account.hpp
	clang++ $(CFLAFGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all