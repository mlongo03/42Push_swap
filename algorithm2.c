/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:17:37 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 11:30:50 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*reset_moves(t_moves *moves)
{
	moves->pa = 0;
	moves->pb = 0;
	moves->sa = 0;
	moves->sb = 0;
	moves->ss = 0;
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	return (moves);
}

int	count_num_moves(t_moves *moves)
{
	int	res;

	res = moves->pa + moves->pb + moves->ra + moves->rb
		+ moves->rr + moves->rra + moves->rrb + moves->rrr
		+ moves->sa + moves->sb + moves->ss;
	return (res);
}

void	copy_moves(t_moves *finalmoves, t_moves *moves)
{
	finalmoves->pa = moves->pa;
	finalmoves->pb = moves->pb;
	finalmoves->sa = moves->sa;
	finalmoves->sb = moves->sb;
	finalmoves->ss = moves->ss;
	finalmoves->ra = moves->ra;
	finalmoves->rb = moves->rb;
	finalmoves->rr = moves->rr;
	finalmoves->rra = moves->rra;
	finalmoves->rrb = moves->rrb;
	finalmoves->rrr = moves->rrr;
}

void	exec_moves(t_moves finalmoves, t_listlink *stack_a, t_listlink *stack_b)
{
	while (finalmoves.rr--)
		rr(stack_a, stack_b);
	while (finalmoves.rrr--)
		rrr(stack_a, stack_b);
	while (finalmoves.ra--)
		ra(stack_a, 1);
	while (finalmoves.rb--)
		rb(stack_b, 1);
	while (finalmoves.rra--)
		rra(stack_a, 1);
	while (finalmoves.rrb--)
		rrb(stack_b, 1);
}

t_listlink	*search_max_node(t_listlink *stack)
{
	t_listlink	*tmp;
	int			nodes;
	int			content;

	content = 0;
	stack = move_on_first(stack);
	nodes = stack->before->index;
	if (stack->content > stack->next->content)
	{
		content = stack->content;
		tmp = stack;
	}
	else
	{
		content = stack->next->content;
		tmp = stack->next;
	}
	while (stack->index != nodes)
		search_max_node2(&stack, &content, &tmp);
	if (stack->content > content)
	{
		content = stack->content;
		tmp = stack;
	}
	return (tmp);
}
