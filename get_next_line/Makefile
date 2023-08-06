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