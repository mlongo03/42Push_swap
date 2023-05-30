/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:44:04 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/29 12:51:40 by alessiolong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_listlink *stack_a)
{
	int	tmp1;
	int	tmp2;

	tmp1 = 0;
	tmp2 = 0;
	while (stack_a->index != 1)
		stack_a = stack_a->next;
	tmp1 = stack_a->content;
	while (stack_a->index != 2)
		stack_a = stack_a->next;
	tmp2 = stack_a->content;
	stack_a->content = tmp1;
	while (stack_a->index != 1)
		stack_a = stack_a->next;
	stack_a->content = tmp2;
}

void	sb(t_listlink *stack_b)
{
	int	tmp1;
	int	tmp2;

	tmp1 = 0;
	tmp2 = 0;
	while (stack_b->index != 1)
		stack_b = stack_b->next;
	tmp1 = stack_b->content;
	while (stack_b->index != 2)
		stack_b = stack_b->next;
	tmp2 = stack_b->content;
	stack_b->content = tmp1;
	while (stack_b->index != 1)
		stack_b = stack_b->next;
	stack_b->content = tmp2;
}

void	ss(t_listlink *stack_a, t_listlink *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_listlink *stack_a, t_listlink *stack_b)
{
	if (stack_b)
	{
		while (stack_b->index != 1)
			stack_b = stack_b->next;

	}
}

// void	pb(t_listlink *stack_a, t_listlink *stack_b)
// {
// }

// void	ra(t_listlink *stack_a)
// {
// }

void	rb(t_listlink *stack_b)
{
	int nodes;

	nodes = 0;
	while (stack_b->index != 1)
		stack_b = stack_b->next;
	nodes = stack_b->before->index;
}

// void	rr(t_listlink *stack_a, t_listlink *stack_b)
// {
// }

// void	rra(t_listlink *stack_a)
// {
// }

// void	rrb(t_listlink *stack_b)
// {
// }

// void	rrr(t_listlink *stack_a, t_listlink *stack_b)
// {
// }

// int tmp;

// while (list->index != 2)
// list = list->next;

// tmp = list->content;
