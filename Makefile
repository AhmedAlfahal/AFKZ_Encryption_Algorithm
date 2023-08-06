CC		=	cc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g3

NAME	=	SimplifiedDES

LIBS	=	get_next_line/gnl.a my_library/Mylib.a


SRC		=	DES.c		\
			DES_utils.c	\
			parse_files.c	\
			error_utils.c

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	@make all -C ./my_library
	@make all -C ./get_next_line
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)
clean:
	@make clean -C ./my_library
	@make clean -C ./get_next_line
	rm -fr $(SRCS)

fclean: clean
	@make fclean -C ./my_library
	@make fclean -C ./get_next_line
	rm -fr $(NAME) 

re: fclean all