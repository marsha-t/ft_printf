NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_strlen.c ft_atoi.c ft_strchr.c 
OFILES = ${CFILES:.c=.o}

all: $(NAME)

%o: %c 
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OFILES) 
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re