NAME	=	libft.a
program =   pipex
HEAD	= 	src/pipex.h
SRC		= 	Exec.c Pipex.c
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -f
SRCS	=	src/ft_strlen.c src/ft_strnstr.c \
			src/ft_strlcpy.c src/ft_strlcat.c \
			src/ft_strdup.c src/ft_strjoin.c src/ft_split.c
			
OBJS	=	$(SRCS:.c=.o)


all: $(program)

$(program): $(NAME)
	$(CC) $(CFLAGS) $(SRC) $(NAME) -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEAD) $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(program)

re: fclean all
.PHONY: all clean fclean re