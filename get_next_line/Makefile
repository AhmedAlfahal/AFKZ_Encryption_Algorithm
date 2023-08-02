# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 17:22:08 by aalfahal          #+#    #+#              #
#    Updated: 2023/07/29 20:48:29 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	gnl.a

SRC	=		get_next_line.c			\
			get_next_line_utils.c

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	ar rc $(NAME) $(SRCS)

clean:
	rm -fr $(SRCS)

fclean: clean
	rm -fr $(NAME)

re: fclean all