# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yitani <yitani@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 00:23:38 by yitani            #+#    #+#              #
#    Updated: 2025/08/29 13:24:43 by yitani           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yitani <yitani@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 22:00:00 by yitani            #+#    #+#              #
#    Updated: 2025/08/28 22:30:00 by yitani           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface_recap

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = src
INCDIR = inc

SRCS = main.cpp \
       $(SRCDIR)/AMateria.cpp \
       $(SRCDIR)/Ice.cpp \
       $(SRCDIR)/Cure.cpp \
       $(SRCDIR)/Character.cpp \
       $(SRCDIR)/MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re