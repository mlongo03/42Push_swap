/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:44:04 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 17:27:01 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/checker.h"

void	ra(t_listlink *stack_a)
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
}

void	rb(t_listlink *stack_b)
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
}

void	rr(t_listlink *stack_a, t_listlink *stack_b)
{
	rb(stack_b);
	ra(stack_a);
}

void	rra(t_listlink *stack_a)
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
}

void	rrb(t_listlink *stack_b)
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
}
