SRC = ft_conversion_format_check.c \
	  ft_convertor_army.c \
	  ft_data_setup_army.c \
	  ft_display_all.c \
	  ft_display_tools.c \
	  ft_flag_initiate.c \
	  ft_libft_army.c \
	  ft_printf.c \
	  ft_printf_tools.c \
	  ft_strjoin.c 
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJ) 
	ar -rcs $@ $(OBJ)
	ranlib $@

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
