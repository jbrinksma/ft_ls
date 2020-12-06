# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbrinksm <jbrinksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 11:44:25 by jbrinksm       #+#    #+#                 #
#    Updated: 2019/03/21 16:43:58 by jbrinksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = strlen strdup strndup strcpy strncpy strcmp strncmp strcat strncat \
strlcat strchr strrchr strstr strnstr isalpha isdigit isalnum isascii isprint \
toupper tolower atoi memset bzero memcpy memccpy memmove memchr memcmp putchar \
putstr putnbr memalloc memdel strdel strnew strclr striter striteri strmap \
strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putendl putchar_fd \
putstr_fd putendl_fd putnbr_fd lstnew lstdelone lstdel lstadd lstiter lstmap \
isspace intlen countwords wordlength \
\
char_to_str lltoa longlonglen putnstr revstr uitoa ulltoa unsintlen \
unslonglonglen malloc_checker findnword strjoin_free

PRINTF_SRCS = \
ft_printf ft_error_printf struct_handlers read_conversion_specification \
replace_conversion_specification conversions_to_str_wrapper poxf_converters \
manipulate_converted_str add_field_width_and_flags diouxx_to_str_wrapper \
add_precision extra_functions conv_type_checker \

SRCS := $(SRCS:%=ft_%.c)

PRINTF_SRCS := $(PRINTF_SRCS:%=%.c)

OBJS = $(SRCS:.c=.o)

PRINTF_OBJS := $(PRINTF_SRCS:.c=.o)

GCC_OBJ = gcc -Iincludes -c -Wall -Werror -Wextra $(SRCS) $(PRINTF_SRCS)

CREATE_LIB = ar -rc $(NAME) $(OBJS) $(PRINTF_OBJS)

$(NAME):
	@echo "[...] Compiling libft library."
	@$(GCC_OBJ)
	@$(CREATE_LIB)
	@ranlib $(NAME)
	@echo "[ + ] Libft library has been compiled."

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(PRINTF_OBJS)
	@echo "[ - ] Removed object files."

fclean: clean
	@rm -f $(NAME)
	@echo "[ - ] Removed libft library."

re: fclean all