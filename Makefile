# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achak <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 11:18:54 by achak             #+#    #+#              #
#    Updated: 2024/03/14 13:32:43 by achak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	:= /bin/bash
NAME	:= so_long
#B_NAME	:= testing_so_long
CC	:= cc -g -Wall -Werror -Wextra
SRCS	= $(wildcard so_long_dir/*.c)
#B_SRCS	= $(wildcard testing_dir/*.c)
OBJ	= $(SRCS:.c=.o)
B_OBJ	= $(B_SRCS:.c=.o)
LIBFT	= libft
LIB_OBJ	= libft/*.o libft/ft_dprintf/*.o

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(MAKE) all -C $(LIBFT)
	$(CC) -Llibft libft/libft.a $(OBJ) $(LIB_OBJ) -I libft/libft.h -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o:%.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $^ -o $@

clean:
	rm -rf $(OBJ)
	if [ -d $(LIBFT) ]; then $(MAKE) clean -C $(LIBFT); fi

fclean:	clean
	rm -rf $(NAME)
ifneq "$(wildcard $(LIBFT) )" ""
	$(MAKE) fclean -C $(LIBFT)
endif

re:	fclean all

#$bonus:	fclean $(B_OBJ) $(LIBFT)
#$	$(MAKE) all -C $(LIBFT)
#$	$(CC) -L libft/libft.a $(B_OBJ) $(LIB_OBJ) -I libft/libft.h -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

.PHONY:	all clean fclean re
#$(CC) -L libft/libft.a $(B_OBJ) $(LIB_OBJ) -o $(B_NAME)
#$(CC) -I/usr/include -Imlx_linux -O3 -c $^ -o $@
