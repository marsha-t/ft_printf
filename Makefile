NAME = libftprintf.a
LIBFT = libft.a
LIBFT_DIR = libft
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_extract_conv.c ft_put.c ft_printf.c \
ft_conv_cs.c ft_conv_p.c ft_conv_di.c ft_conv_ux.c 
# ft_libft.c 
OFILES = ${CFILES:.c=.o}

all: $(NAME)

%o: %c 
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(LIBFT) $(OFILES)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OFILES)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OFILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(LIBFT) $(OFILES)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OFILES)

.PHONY: all clean fclean re bonus
