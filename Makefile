NAME	= main
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror 

SRC		= ft_bzero.c ft_strtrim.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	  ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_split.c\
	  ft_itoa.c
OBJ		= $(SRC:.c=.o)
AR		= ar rcs
MAIN	= main.o
LIB 	= libft.a

all : $(NAME)

$(NAME) : $(MAIN) $(LIB)
	$(CC) $(CFLAGS) $(MAIN) $(LIB) -o $@

$(LIB) : $(OBJ)
	$(AR) $(LIB) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(MAIN) main

fclean : clean
	rm -f $(LIB)  

re : fclean all

.PHONY : all clean fclean re
