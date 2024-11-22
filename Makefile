
CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADERS = libft/libft.h ft_printf.h
SRCS = ft_printf.c ft_itoa_base.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c \
	libft/ft_strlen.c ft_uitoa_base.c ft_ltoa_base.c ft_handle_pointer_specifier.c \
	ft_handle_str_specifier.c ft_check_valid_spec.c libft/ft_strchr.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ${HEADERS}
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY: all clean fclean re
