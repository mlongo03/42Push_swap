/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:44:11 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/26 15:19:48 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

void	ft_error(void);
t_listlink	*create_stack_a(char **argv, int argc);
// void	sa(t_listlink *stack_a);
// void	sb(t_listlink *stack_b);
// void	ss(t_listlink *stack_a, t_listlink *stack_b);
// void	pa(t_listlink *stack_a, t_listlink *stack_b);
// void	pb(t_listlink *stack_a, t_listlink *stack_b);
// void	ra(t_listlink *stack_a);
// void	rb(t_listlink *stack_b);
// void	rr(t_listlink *stack_a, t_listlink *stack_b);
// void	rra(t_listlink *stack_a);
// void	rrb(t_listlink *stack_b);
// void	rrr(t_listlink *stack_a, t_listlink *stack_b);

#endif
