CC		=	cc

CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=address 

NAME	=	AFKZ_encryption

LIBS	=	get_next_line/gnl.a my_library/Mylib.a


SRC		=	srcs/AFKZ.c			\
			srcs/AFKZ_utils.c	\
			srcs/parse_files.c	\
			srcs/error_utils.c	\
			srcs/printer_utils.c		\
			srcs/iSbox_utils.c

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