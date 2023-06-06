# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstocche <mstocche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 16:18:44 by mlongo            #+#    #+#              #
#    Updated: 2023/06/06 18:38:49 by mstocche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

NAME_BONUS := checker

OBJS := push_swap.o moves.o moves2.o moves3.o utils.o utils2.o algorithm.o algorithm2.o algorithm3.o algorithm4.o algorithm5.o

OBJS_BONUS := ./bonus/checker.o ./bonus/utils.o ./bonus/get_next_line.o ./bonus/get_next_line_utils.o ./bonus/moves.o ./bonus/moves2.o ./bonus/moves3.o ./bonus/checker1.o

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

bonus: $(NAME_BONUS)

%.o : %.c
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@make bonus -C libft
	@make -C ft_printf
	@cc $(OBJS) ${LIBFT} $(FT_PRINTF) -o $(NAME) -fsanitize=address
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C libft
	@make bonus -C libft
	@make -C ft_printf
	@cc $(OBJS_BONUS) ${LIBFT} $(FT_PRINTF) -o $(NAME_BONUS) -fsanitize=address
	@echo "$(GREEN)$(NAME_BONUS) created!$(DEFAULT)"

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -f $(OBJS) ${OBJS_BONUS}
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: clean fclean all
