# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phtruong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 09:57:26 by phtruong          #+#    #+#              #
#    Updated: 2019/04/05 14:29:46 by phtruong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
INCL = ./libft/libft.a
OBJS = *.o
SRCS = pre_read.c validate.c main.c tet_read.c 
MAKE = make -C libft/ fclean && make -C libft/ 

all:
	@$(MAKE)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(INCL)

clean:
	rm -rf $(OBJS)
	@make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all
