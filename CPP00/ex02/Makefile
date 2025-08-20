# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yitani <yitani@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 18:16:21 by yitani            #+#    #+#              #
#    Updated: 2025/08/20 18:16:25 by yitani           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account_test

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re