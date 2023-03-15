# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#              #
#    Updated: 2023/03/15 16:07:26 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=btc

SRCS=main.cpp BitcoinExchange.cpp
OBJS=$(SRCS:.cpp=.o)
INCS=BitcoinExchange.hpp

CC=clang++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g3
INCLUDES=$(addprefix -I , $(INCS))

RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all