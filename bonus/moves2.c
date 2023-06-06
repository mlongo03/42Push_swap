/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:34:15 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 17:26:46 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/checker.h"

void	sa(t_listlink *stack_a)
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
	}
}

void	sb(t_listlink *stack_b)
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
	}
}

void	ss(t_listlink *stack_a, t_listlink *stack_b)
{
	if (stack_a || stack_b)
	{
		sa(stack_a);
		sb(stack_b);
	}
}
