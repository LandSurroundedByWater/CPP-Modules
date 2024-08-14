# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 19:11:42 by tsaari            #+#    #+#              #
#    Updated: 2024/07/23 10:11:33 by tsaari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixedfloat

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean 
