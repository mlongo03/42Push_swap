/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:44:04 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/30 18:48:55 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_listlink *stack_a, int flag)
{
	int			tmpfinal;

	while (stack_a->index != 1)
		stack_a = stack_a->next;
	tmpfinal = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a->index != 1)
	{
		stack_a->before->content = stack_a->content;
		stack_a = stack_a->next;
	}
	stack_a->before->content = tmpfinal;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_listlink *stack_b, int flag)
{
	int			tmpfinal;

	while (stack_b->index != 1)
		stack_b = stack_b->next;
	tmpfinal = stack_b->content;
	stack_b = stack_b->next;
	while (stack_b->index != 1)
	{
		stack_b->before->content = stack_b->content;
		stack_b = stack_b->next;
	}
	stack_b->before->content = tmpfinal;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_listlink *stack_a, t_listlink *stack_b)
{
	rb(stack_b, 0);
	ra(stack_a, 0);
	write(1, "rr\n", 3);
}

void	rra(t_listlink *stack_a, int flag)
{
	int			tmpfinal;

	while (stack_a->index != 1)
		stack_a = stack_a->next;
	stack_a = stack_a->before;
	tmpfinal = stack_a->content;
	stack_a = stack_a->before;
	while (stack_a->index != 1)
	{
		stack_a->next->content = stack_a->content;
		stack_a = stack_a->before;
	}
	stack_a->next->content = stack_a->content;
	stack_a->content = tmpfinal;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_listlink *stack_b, int flag)
{
	int			tmpfinal;

	while (stack_b->index != 1)
		stack_b = stack_b->next;
	stack_b = stack_b->before;
	tmpfinal = stack_b->content;
	stack_b = stack_b->before;
	while (stack_b->index != 1)
	{
		stack_b->next->content = stack_b->content;
		stack_b = stack_b->before;
	}
	stack_b->next->content = stack_b->content;
	stack_b->content = tmpfinal;
	if (flag)
		write(1, "rrb\n", 4);
}
