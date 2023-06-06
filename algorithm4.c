/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:17:29 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 11:11:22 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_min_than_node2(t_listlink *stack_b, t_listlink **tmp, int *flag)
{
	*flag += 1;
	if (*flag == 1)
		*tmp = stack_b;
	if ((*tmp)->content < stack_b->content)
		*tmp = stack_b;
}

t_listlink	*search_min_than_node(t_listlink *stack_a, t_listlink *stack_b)
{
	int			nodes;
	t_listlink	*tmp;
	int			flag;

	flag = 0;
	nodes = stack_b->before->index;
	tmp = stack_a;
	while (stack_b->index != nodes)
	{
		if (stack_a->content > stack_b->content)
		{
			flag++;
			if (flag == 1)
				tmp = stack_b;
			if (tmp->content < stack_b->content)
				tmp = stack_b;
		}
		stack_b = stack_b->next;
	}
	if (stack_a->content > stack_b->content)
		search_min_than_node2(stack_b, &tmp, &flag);
	return (tmp);
}

void	search_max_node2(t_listlink **stack, int *content, t_listlink **tmp)
{
	if ((*stack)->content > *content)
	{
		*content = (*stack)->content;
		*tmp = *stack;
	}
	*stack = (*stack)->next;
}

void	count_moves_node2(t_listlink *stack_a, t_listlink *stack_b,
	t_utils *utils, t_minmax minmax)
{
	if (minmax.num_min == utils->nodes_b || minmax.num_max == utils->nodes_b)
	{
		count_put_my_node_on_top_a(stack_a, &utils->moves);
		stack_b = search_max_node(stack_b);
		count_put_my_node_on_top_b(stack_b, &utils->moves);
		handle_double_r(utils);
	}
	else
	{
		stack_b = search_min_than_node(stack_a, stack_b);
		count_put_my_node_on_top_b(stack_b, &utils->moves);
		count_put_my_node_on_top_a(stack_a, &utils->moves);
		handle_double_r(utils);
	}
}

void	count_moves_node(t_listlink **stack_a,
	t_listlink *stack_b, t_utils *utils)
{
	t_minmax	minmax;

	minmax.num_max = 0;
	minmax.num_min = 0;
	stack_b = move_on_first(stack_b);
	while (stack_b->index != utils->nodes_b)
	{
		if ((*stack_a)->content > stack_b->content)
			minmax.num_max++;
		else
			minmax.num_min++;
		stack_b = stack_b->next;
	}
	if ((*stack_a)->content > stack_b->content)
		minmax.num_max++;
	else
		minmax.num_min++;
	count_moves_node2(*stack_a, stack_b, utils, minmax);
	if (count_num_moves(&utils->moves) < utils->countmovesofnode)
	{
		copy_moves(&utils->finalmoves, &utils->moves);
		utils->countmovesofnode = count_num_moves(&utils->moves);
	}
	reset_moves(&utils->moves);
	*stack_a = (*stack_a)->next;
}
