NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c
OFILES = ${CFILES:.c=.o}

all: $(NAME)

%o: %c 
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OFILES) 
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OFILES)
	ar rcs $(NAME) $(OFILES)

.PHONY: all clean fclean re bonus
