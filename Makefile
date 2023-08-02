CC		=	cc

CFLAGS	= -Wall -Wextra -Werror

NAME	=	SimplifiedDES

LIBS	=	get_next_line/gnl.a


SRC		=	DES.c		\
			DES_utils.c

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	@make all -C ./get_next_line
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)
clean:
	@make clean -C ./get_next_line
	rm -fr $(SRCS)

fclean: clean
	@make fclean -C ./get_next_line
	rm -fr $(NAME) 

re: fclean all