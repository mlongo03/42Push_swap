# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 16:18:44 by mlongo            #+#    #+#              #
#    Updated: 2023/05/30 14:42:04 by mlongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

OBJS := push_swap.o moves.o

LIBFT_PATH = ./libft

LIBFT = ${LIBFT_PATH}/libft.a

FT_PRINTF_PATH = ./ft_printf

FT_PRINTF = ${FT_PRINTF_PATH}/libftprintf.a

FLAGS := -Wall -Werror -Wextra

#COLORS
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

all: $(NAME)

%.o : %.c
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@make bonus -C libft
	@make -C ft_printf
	@cc $(OBJS) ${LIBFT} $(FT_PRINTF) -o $(NAME) -fsanitize=address
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -f $(OBJS) ${OBJS_BONUS}
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: clean fclean all
