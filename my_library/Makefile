NAME	= 	Mylib.a

CC		= 	cc

CFLAGS	= 	-Wall -Wextra -Werror

OBJ		=	my_strlen.c		\
			my_isdigit.c	\
			my_bzero.c		\
			my_strdup.c		\
			my_substr.c		
			
OBJS 	= 	$(OBJ:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: clean all
