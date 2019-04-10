# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phtruong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 09:57:26 by phtruong          #+#    #+#              #
#    Updated: 2019/04/10 13:15:56 by phtruong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCL = -Iincludes/ 
INCL_LIB = ./libft/libft.a
OBJS = main.o pre_read.o validate.o tab_trans.o \
	   stack.o free_fn.o grid.o collision.o
SRCS_DIR = srcs/
FILL_SRCS = main.c pre_read.c validate.c tab_trans.c \
	   stack.c free_fn.c grid.c collision.c 
SRCS = $(addprefix $(SRCS_DIR), $(FILL_SRCS))
LIB = make -C ./libft/

all: $(NAME)

$(NAME):
		$(LIB)
		@$(CC) $(CFLAGS) -c $(SRCS) $(INCL)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCL_LIB)


clean:
	rm -rf $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft/ fclean

re: fclean all
