NAME = fdf

SRCS = main.c \
	   fdf_array_functions.c \
	   fdf_utils.c \
		$(addprefix get_next_line/, get_next_line.c) \
		$(addprefix libft/, ft_atoi.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strlen.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_strjoin.c ft_substr.c ft_isalpha.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strncmp.c ft_memcmp.c ft_memchr.c ft_calloc.c ft_strlcat.c ft_strtrim.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_freed_split.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C minilibx 2>/dev/null
	@gcc $(CFLAGS) -o $(NAME) $(SRCS) -lmlx -framework OpenGL -framework AppKit -lm -L minilibx
	@echo "\n✅ $(GREEN)SUCCESS: $(NAME) has been created$(RESET)\n"

clean:
	@make clean -C minilibx
	@rm -rf $(OBJS)
	@echo "\n$(RED)SUCCESS: object files have been deleted$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "\n$(RED)SUCCESS: object files and $(NAME) have been deleted$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
