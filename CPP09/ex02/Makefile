# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 09:11:55 by tsaari            #+#    #+#              #
#    Updated: 2025/02/05 17:10:04 by tsaari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -g -fsanitize=address

SRCS = main.cpp #PmergeMe.cpp
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

.PHONY: all clean fclean re

