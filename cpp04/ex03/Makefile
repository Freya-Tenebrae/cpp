# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/08/10 16:12:52 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=materia

SRCS=main.cpp\
		AMateria.cpp\
		Cure.cpp\
		Ice.cpp\
		MateriaSource.cpp\
		Character.cpp
OBJS=$(SRCS:.cpp=.o)
INCS=AMateria.hpp\
		Cure.hpp\
		Ice.hpp\
		IMateriaSource.hpp\
		MateriaSource.hpp\
		ICharacter.hpp\
		Character.hpp

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