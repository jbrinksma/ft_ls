# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbrinksm <jbrinksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/15 16:28:31 by jbrinksm       #+#    #+#                 #
#    Updated: 2019/03/21 16:50:15 by jbrinksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = main input_handler struct_management recursive_searching sorting_stuff \
find_display_padding tools file_reading l_flag_function l_flag_mode_to_str \
get_info non_recursive_searching combine_paths total_blocks

SRCS := $(SRCS:%=srcs/%.c)

LIB_AND_HEAD = -Iincludes -Isrcs/libft/includes -Lsrcs/libft -lft

GCC = gcc

$(NAME):
	@make -C srcs/libft/
	@echo "[...] Compiling ft_ls."
	@$(GCC) $(SRCS) $(LIB_AND_HEAD) -o $(NAME)
	@echo "[ + ] ft_ls has been compiled."

all: $(NAME)

clean:
	@make clean -C srcs/libft/
	@rm -rf *~
	@echo "[ - ] Removed *~ files."

fclean: clean
	@make fclean -C srcs/libft/
	@rm -rf $(NAME)
	@echo "[ - ] Removed ft_ls."

prog: re
	gcc -Wall -Werror -Wextra -Llibft -lft main.c -o printf_test

re: fclean all