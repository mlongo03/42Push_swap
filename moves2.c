/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:34:15 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 11:27:01 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_listlink *stack_a, int flag)
{
	int	tmp1;

	tmp1 = 0;
	if (stack_a)
	{
		while (stack_a->index != 1)
			stack_a = stack_a->next;
		tmp1 = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp1;
		if (flag)
			write(1, "sa\n", 3);
	}
}

void	sb(t_listlink *stack_b, int flag)
{
	int	tmp1;

	tmp1 = 0;
	if (stack_b)
	{
		while (stack_b->index != 1)
			stack_b = stack_b->next;
		tmp1 = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp1;
		if (flag)
			write(1, "sb\n", 3);
	}
}

void	ss(t_listlink *stack_a, t_listlink *stack_b)
{
	if (stack_a || stack_b)
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
		write(1, "ss\n", 3);
	}
}
