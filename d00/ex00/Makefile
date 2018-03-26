# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2018/03/26 16:09:47 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

SRC			= megaphone.cpp
OBJ			= megaphone.o

CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -pedantic -std=c++98
# CXXFLAGS   += -O3 -march=native -pipe -flto

.PHONY: all clean fclean re

all: $(NAME)

%.o:%.c
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
