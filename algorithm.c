/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:51:14 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 11:32:32 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting2(t_listlink *stack_a)
{
	if (stack_a->content > stack_a->next->content)
		sa(stack_a, 1);
}

void	sorting4(t_listlink *stack_a, t_listlink *stack_b)
{
	int			content;
	int			nodes;
	t_listlink	*tmp;

	content = 0;
	nodes = 0;
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	stack_a = move_on_first(stack_a);
	stack_b = move_on_first(stack_b);
	sorting3(stack_a);
	while (stack_b->next != NULL)
		sorting_push(move_on_first(stack_a), move_on_first(stack_b));
	sorting_push(move_on_first(stack_a), move_on_first(stack_b));
	stack_a = move_on_first(stack_a);
	nodes = stack_a->before->index;
	calc_min(&tmp, &stack_a, &content, nodes);
	push_min_on_top(stack_a, nodes, content, tmp);
}

void	sorting3(t_listlink *stack_a)
{
	stack_a = move_on_first(stack_a);
	if (stack_a->content < stack_a->next->content)
	{
		if (stack_a->next->content > stack_a->next->next->content)
		{
			if (stack_a->content > stack_a->next->next->content)
				rra(stack_a, 1);
			else
			{
				sa(stack_a, 1);
				ra(stack_a, 1);
			}
		}
	}
	else
	{
		if (stack_a->next->content > stack_a->next->next->content)
		{
			ra(stack_a, 1);
			sa(stack_a, 1);
		}
		else
			if (stack_a->content < stack_a->next->next->content)
				sa(stack_a, 1);
	}
}

void	sorting5(t_listlink *stack_a, t_listlink *stack_b)
{
	int			content;
	int			nodes;
	t_listlink	*tmp;

	content = 0;
	nodes = 0;
	stack_a = move_on_first(stack_a);
	stack_b = move_on_first(stack_b);
	sorting3(stack_a);
	while (stack_b->next != NULL)
		sorting_push(move_on_first(stack_a), move_on_first(stack_b));
	sorting_push(move_on_first(stack_a), move_on_first(stack_b));
	stack_a = move_on_first(stack_a);
	nodes = stack_a->before->index;
	calc_min(&tmp, &stack_a, &content, nodes);
	push_min_on_top(stack_a, nodes, content, tmp);
}

void	sorting10(t_listlink *stack_a, t_listlink *stack_b)
{
	t_utils	utils;
	int		nodes_a;

	utils.countmovesofnode = 999999;
	reset_moves(&utils.moves);
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	utils.nodes_b = move_on_first(stack_b)->before->index;
	nodes_a = move_on_first(stack_a)->before->index;
	while (nodes_a != 3)
	{
		stack_a = move_on_first(stack_a);
		while (stack_a->index != nodes_a)
			count_moves_node(&stack_a, stack_b, &utils);
		count_moves_node(&stack_a, stack_b, &utils);
		exec_moves(utils.finalmoves, stack_a, stack_b);
		pb(stack_a, stack_b, 1);
		stack_a = stack_a->next;
		utils.nodes_b = move_on_first(stack_b)->before->index;
		nodes_a = move_on_first(stack_a)->before->index;
		utils.countmovesofnode = 999999;
	}
	sorting5(stack_a, stack_b);
}
