/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:44:11 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/30 17:05:21 by mlongo           ###   ########.fr       */
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
void	sa(t_listlink *stack_a, int flag);
void	sb(t_listlink *stack_b, int flag);
void	ss(t_listlink *stack_a, t_listlink *stack_b);
void	pa(t_listlink *stack_a, t_listlink *stack_b, int flag);
void	pb(t_listlink *stack_a, t_listlink *stack_b, int flag);
void	ra(t_listlink *stack_a, int flag);
void	rb(t_listlink *stack_b, int flag);
void	rr(t_listlink *stack_a, t_listlink *stack_b);
void	rra(t_listlink *stack_a, int flag);
void	rrb(t_listlink *stack_b, int flag);
void	rrr(t_listlink *stack_a, t_listlink *stack_b);

#endif
