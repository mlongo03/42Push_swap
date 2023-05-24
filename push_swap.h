/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:44:11 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/24 19:26:17 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_listlink
{
	struct s_listlink	*before;
	struct s_listlink	*next;
	int					content;
	int					head;
}	t_listlink;


void	sa(t_listlink *stack_a);
void	sb(t_listlink *stack_b);
void	ss(t_listlink *stack_a, t_listlink *stack_b);
void	pa(t_listlink *stack_a, t_listlink *stack_b);
void	pb(t_listlink *stack_a, t_listlink *stack_b);
void	ra(t_listlink *stack_a);
void	rb(t_listlink *stack_b);
void	rr(t_listlink *stack_a, t_listlink *stack_b);
void	rra(t_listlink *stack_a);
void	rrb(t_listlink *stack_b);
void	rrr(t_listlink *stack_a, t_listlink *stack_b);

#endif
