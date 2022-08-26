# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeham <yeham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 14:40:43 by yeham             #+#    #+#              #
#    Updated: 2022/08/12 14:57:37 by yeham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_itoahex.c ft_itoahex_large.c \
		go_series.c go_series2.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -I.

all : $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp  ./libft/libft.a $(NAME)
	ar -rcs $@ $^
	
%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean :
	$(MAKE) -C ./libft fclean
	make clean
	rm -f $(NAME) 

re : 
	make fclean
	make all

.PHONY : all clean fclean re
