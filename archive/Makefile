NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CFILES = main.c
OFILES = ${CFILES:.c=.o}

all: $(NAME)

%o: %c 
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OFILES) 
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES) $(BONUS_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OFILES) $(BONUS_OFILES)
	ar rcs $(NAME) $(OFILES) $(BONUS_OFILES)

.PHONY: all clean fclean re bonus
