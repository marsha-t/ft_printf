NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c ft_libft.c ft_conv.c
OFILES = ${CFILES:.c=.o}
BONUS_CFILES = ft_printf_bonus.c
BONUS_OFILES = ${BONUS_CFILES:.c=.o}

all: $(NAME)

%o: %c 
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): fclean $(OFILES) 
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES) $(BONUS_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: fclean $(BONUS_OFILES)
	ar rcs $(NAME) $(BONUS_OFILES)

.PHONY: all clean fclean re bonus
