/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:17:32 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 11:10:32 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_put_my_node_on_top_a2(t_listlink *stack, t_moves *moves,
	t_countr *countr, int flag)
{
	if (flag == 1)
	{
		countr->countra += 1;
		moves->ra++;
		ra(stack, 0);
	}
	else
	{
		countr->countrra += 1;
		moves->rra++;
		rra(stack, 0);
	}
}

void	count_put_my_node_on_top_a(t_listlink *stack, t_moves *moves)
{
	int			content;
	int			nodes;
	t_countr	countr;

	countr.countra = 0;
	countr.countrra = 0;
	nodes = move_on_first(stack)->before->index;
	content = stack->content;
	if (nodes % 2 != 0)
		nodes = nodes + 1;
	if (stack->index <= (nodes / 2))
		while (move_on_first(stack)->content != content)
			count_put_my_node_on_top_a2(stack, moves, &countr, 1);
	else
		while (move_on_first(stack)->content != content)
			count_put_my_node_on_top_a2(stack, moves, &countr, 2);
	while (countr.countra--)
		rra(stack, 0);
	while (countr.countrra--)
		ra(stack, 0);
}

void	count_put_my_node_on_top_b2(t_listlink *stack, t_moves *moves,
	t_countr *countr, int flag)
{
	if (flag == 1)
	{
		countr->countra += 1;
		moves->rb++;
		ra(stack, 0);
	}
	else
	{
		countr->countrra += 1;
		moves->rrb++;
		rra(stack, 0);
	}
}

void	count_put_my_node_on_top_b(t_listlink *stack, t_moves *moves)
{
	int			content;
	int			nodes;
	t_countr	countr;

	countr.countra = 0;
	countr.countrra = 0;
	nodes = move_on_first(stack)->before->index;
	content = stack->content;
	if (nodes % 2 != 0)
		nodes = nodes + 1;
	if (stack->index <= (nodes / 2))
		while (move_on_first(stack)->content != content)
			count_put_my_node_on_top_b2(stack, moves, &countr, 1);
	else
		while (move_on_first(stack)->content != content)
			count_put_my_node_on_top_b2(stack, moves, &countr, 2);
	while (countr.countra--)
		rrb(stack, 0);
	while (countr.countrra--)
		rb(stack, 0);
}

void	calc_min(t_listlink **tmp, t_listlink **stack_a,
	int *content, int nodes)
{
	if ((*stack_a)->content < (*stack_a)->next->content)
	{
		*tmp = *stack_a;
		*content = (*stack_a)->content;
	}
	else
	{
		*tmp = (*stack_a)->next;
		*content = (*stack_a)->next->content;
	}
	while ((*stack_a)->index != nodes)
	{
		if ((*stack_a)->content < *content)
		{
			*tmp = *stack_a;
			*content = (*stack_a)->content;
		}
		*stack_a = (*stack_a)->next;
	}
	if ((*stack_a)->content < *content)
	{
		*tmp = *stack_a;
		*content = (*stack_a)->content;
	}
}
