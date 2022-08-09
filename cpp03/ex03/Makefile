# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/08/09 14:00:02 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=diamondTrap

SRCS=main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS=$(SRCS:.cpp=.o)
INCS=ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

CC=clang++
CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c++98 -g3
INCLUDES=$(addprefix -I , $(INCS))

RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all