NAME	=	libft.a
program =   pipex
HEAD	= 	src/pipex.h
SRC		= 	Exec.c Pipex.c
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -f
SRCS	=	 src/ft_strlen.c src/ft_strnstr.c\
			src/ft_strlcpy.c src/ft_strlcat.c \
			src/ft_strdup.c src/ft_strjoin.c src/ft_split.c \
			

OBJS	=	$(SRCS:%.c=%.o)

%.o : %.c $(HEAD) $(SRC) pro
	$(CC) $(CFLAGS) -c -o $@ $<
all :  $(NAME) $(pro)
		$(CC)  $(CFLAGS) $(SRC) $(NAME) -o $(program)


$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
 
			

clean:
	$(RM) $(OBJS)
pro:
	$(RM) $(program)

fclean: clean
	$(RM) $(NAME) $(pro)

re: fclean all



# NAME	=	libft.a
# program =   pipex
# HEAD	= 	src/pipex.h
# SRC		= 	Exec.c Pipex.c
# CC		=	cc
# CFLAGS	=	-Wall -Wextra -Werror
# AR		=	ar rc
# RM		=	rm -f
# SRCS	=	 src/ft_strlen.c src/ft_strnstr.c\
# 			src/ft_strlcpy.c src/ft_strlcat.c \
# 			src/ft_strdup.c src/ft_strjoin.c src/ft_split.c \
			

# OBJS	=	$(SRCS:%c=%o)


# %o	:	%c $(HEAD) $(SRC)
# 			$(CC) $(CFLAGS) -c -o $@ $<

# $(NAME)	:	$(OBJS)
# 			ar rc $(NAME) $(OBJS)
# $(program): $(NAME)
# 			cc Exec.c Pipex.c $(CFLAGS)  libft.a -o pipex
			
# all	:   $(program) 
# clean:
# 			$(RM) $(OBJS)

# fclean:	clean
# 			$(RM) $(NAME) $(program)

# re:	fclean all
