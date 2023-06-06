/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:17:24 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 11:12:07 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	detect_node_to_push(int *flag, t_listlink **tmp,
	t_listlink *stack_a, t_listlink *stack_b)
{
	if (stack_b->content < stack_a->content)
	{
		*flag += 1;
		if (*flag == 1)
			*tmp = stack_a;
		if ((*tmp)->content > stack_a->content)
			*tmp = stack_a;
	}
}

void	sorting_push2(t_listlink **stack_a, t_listlink *stack_b,
	t_listlink **tmp, t_utils2 *utils)
{
	int	flag;

	flag = 0;
	while ((*stack_a)->index != utils->nodes)
	{
		detect_node_to_push(&flag, tmp, *stack_a, stack_b);
		*stack_a = (*stack_a)->next;
	}
	detect_node_to_push(&flag, tmp, *stack_a, stack_b);
	if ((*tmp)->content == stack_b->content)
	{
		*stack_a = move_on_first(*stack_a);
		if ((*stack_a)->content < (*stack_a)->next->content)
			utils->content = (*stack_a)->content;
		else
			utils->content = (*stack_a)->next->content;
		while ((*stack_a)->index != utils->nodes)
		{
			if ((*stack_a)->content < utils->content)
				utils->content = (*stack_a)->content;
			*stack_a = (*stack_a)->next;
		}
	}
	else
		utils->content = (*tmp)->content;
}

void	sorting_push(t_listlink *stack_a, t_listlink *stack_b)
{
	t_listlink	*tmp;
	int			flag;
	t_utils2	utils;

	flag = 0;
	utils.nodes = stack_a->before->index;
	tmp = stack_b;
	sorting_push2(&stack_a, stack_b, &tmp, &utils);
	if (utils.nodes % 2 != 0)
		utils.nodes = utils.nodes + 1;
	if (tmp->index <= (utils.nodes / 2))
	{
		while (move_on_first(stack_a)->content != utils.content)
			ra(stack_a, 1);
	}
	else
	{
		while (move_on_first(stack_a)->content != utils.content)
			rra(stack_a, 1);
	}
	pa(stack_a, stack_b, 1);
	stack_b = stack_b->next;
}

void	push_min_on_top(t_listlink *stack_a, int nodes,
	int content, t_listlink *tmp)
{
	if (nodes % 2 != 0)
		nodes = nodes + 1;
	if (tmp->index <= (nodes / 2))
	{
		while (move_on_first(stack_a)->content != content)
			ra(stack_a, 1);
	}
	else
	{
		while (move_on_first(stack_a)->content != content)
			rra(stack_a, 1);
	}
}

void	handle_double_r(t_utils *utils)
{
	while (utils->moves.ra != 0 && utils->moves.rb != 0)
	{
		utils->moves.ra--;
		utils->moves.rb--;
		utils->moves.rr++;
	}
	while (utils->moves.rra != 0 && utils->moves.rrb != 0)
	{
		utils->moves.rra--;
		utils->moves.rrb--;
		utils->moves.rrr++;
	}
	while (utils->moves.sa != 0 && utils->moves.sb != 0)
	{
		utils->moves.sa--;
		utils->moves.sb--;
		utils->moves.ss++;
	}
	utils->moves.pb++;
}
