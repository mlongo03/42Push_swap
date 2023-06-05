/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:51:14 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/05 15:50:28 by mlongo           ###   ########.fr       */
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
			+ moves->rr + moves->rra + moves->rrb+ moves->rrr
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
	{
		flag++;
		if (flag == 1)
			tmp = stack_b;
		if (tmp->content < stack_b->content)
			tmp = stack_b;
	}
	return (tmp);
}

void	put_my_node_on_top_a(t_listlink *stack)
{
	int content;
	int	nodes;

	nodes = move_on_first(stack)->before->index;
	content = stack->content;
	if (nodes % 2 != 0)
		nodes = nodes + 1;
	if (stack->index <= (nodes / 2))
	{
		while (move_on_first(stack)->content != content)
			ra(stack, 1);
	}
	else
	{
		while (move_on_first(stack)->content != content)
			rra(stack, 1);
	}
}

void	put_my_node_on_top_b(t_listlink *stack)
{
	int content;
	int	nodes;

	nodes = move_on_first(stack)->before->index;
	content = stack->content;
	if (nodes % 2 != 0)
		nodes = nodes + 1;
	if (stack->index <= (nodes / 2))
	{
		while (move_on_first(stack)->content != content)
			rb(stack, 1);
	}
	else
	{
		while (move_on_first(stack)->content != content)
			rrb(stack, 1);
	}
}

void	count_put_my_node_on_top_a(t_listlink *stack, t_moves *moves)
{
	int content;
	int	nodes;
	int	countra;
	int	countrra;

	countra = 0;
	countrra = 0;
	nodes = move_on_first(stack)->before->index;
	content = stack->content;
	if (nodes % 2 != 0)
		nodes = nodes + 1;
	if (stack->index <= (nodes / 2))
	{
		while (move_on_first(stack)->content != content)
		{
			countra++;
			moves->ra++;
			ra(stack, 0);
		}
	}
	else
	{
		while (move_on_first(stack)->content != content)
		{
			countrra++;
			moves->rra++;
			rra(stack, 0);
		}
	}
	while (countra--)
		rra(stack, 0);
	while (countrra--)
		ra(stack, 0);
}

void	count_put_my_node_on_top_b(t_listlink *stack, t_moves *moves)
{
	int content;
	int	nodes;
	int	countra;
	int	countrra;

	countra = 0;
	countrra = 0;
	nodes = move_on_first(stack)->before->index;
	content = stack->content;
	if (nodes % 2 != 0)
		nodes = nodes + 1;
	if (stack->index <= (nodes / 2))
	{
		while (move_on_first(stack)->content != content)
		{
			countra++;
			moves->rb++;
			rb(stack, 0);
		}
	}
	else
	{
		while (move_on_first(stack)->content != content)
		{
			countrra++;
			moves->rrb++;
			rrb(stack, 0);
		}
	}
	while (countra--)
		rrb(stack, 0);
	while (countrra--)
		rb(stack, 0);
}

t_listlink	*search_max_node(t_listlink *stack)
{
	t_listlink	*tmp;
	int	nodes;
	int	content;

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
	{
		if (stack->content > content)
		{
			content = stack->content;
			tmp = stack;
		}
		stack = stack->next;
	}
	if (stack->content > content)
	{
		content = stack->content;
		tmp = stack;
	}
	return (tmp);
}

void	sorting3(t_listlink *stack_a)
{
	stack_a = move_on_first(stack_a);
	if (stack_a->content < stack_a->next->content)
	{
		if(stack_a->next->content > stack_a->next->next->content)
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
		{
			if (stack_a->content > stack_a->next->next->content)
				;
			else
				sa(stack_a, 1);
		}
	}
}

void	sorting_push(t_listlink *stack_a, t_listlink *stack_b)
{
	int			nodes;
	t_listlink	*tmp;
	int			flag;
	int			content;

	flag = 0;
	nodes = stack_a->before->index;
	tmp = stack_b;
	while (stack_a->index != nodes)
	{
		if (stack_b->content < stack_a->content)
		{
			flag++;
			if (flag == 1)
				tmp = stack_a;
			if (tmp->content > stack_a->content)
				tmp = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (stack_b->content < stack_a->content)
	{
		flag++;
		if (flag == 1)
			tmp = stack_a;
		if (tmp->content > stack_a->content)
			tmp = stack_a;
	}
	if (tmp->content == stack_b->content)
	{
		stack_a = move_on_first(stack_a);
		if (stack_a->content < stack_a->next->content)
			content = stack_a->content;
		else
			content = stack_a->next->content;
		while (stack_a->index != nodes)
		{
			if (stack_a->content < content)
				content = stack_a->content;
			stack_a = stack_a->next;
		}
	}
	else
		content = tmp->content;
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
	pa(stack_a, stack_b, 1);
	stack_b = stack_b->next;
}

void	sorting5(t_listlink *stack_a, t_listlink *stack_b)
{
	int	content;
	int	nodes;
	t_listlink	*tmp;

	content = 0;
	nodes = 0;
	stack_a = move_on_first(stack_a);
	stack_b = move_on_first(stack_b);
	sorting3(stack_a);
	// print_nodes(stack_a, 3);
	while (stack_b->next != NULL)
	{
		sorting_push(move_on_first(stack_a), move_on_first(stack_b));
	}
	sorting_push(move_on_first(stack_a), move_on_first(stack_b));
	stack_a = move_on_first(stack_a);
	nodes = stack_a->before->index;
	if (stack_a->content < stack_a->next->content)
	{
		tmp = stack_a;
		content = stack_a->content;
	}
	else
	{
		tmp = stack_a->next;
		content = stack_a->next->content;
	}
	while (stack_a->index != nodes)
	{
		if (stack_a->content < content)
		{
			tmp = stack_a;
			content = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	if (stack_a->content < content)
	{
		tmp = stack_a;
		content = stack_a->content;
	}
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

void	count_moves_node(t_listlink *stack_a, t_listlink *stack_b, t_utils *utils)
{
	int	num_max;
	int	num_min;

	num_max = 0;
	num_min = 0;
	stack_b = move_on_first(stack_b);
	while(stack_b->index != utils->nodes_b)
	{
		if (stack_a->content > stack_b->content)
			num_max++;
		else
			num_min++;
		stack_b = stack_b->next;
	}
	if (stack_a->content > stack_b->content)
		num_max++;
	else
		num_min++;
	if (num_min == utils->nodes_b || num_max == utils->nodes_b)
	{
		count_put_my_node_on_top_a(stack_a, &utils->moves);
		stack_b = search_max_node(stack_b);
		count_put_my_node_on_top_b(stack_b, &utils->moves);
		while(utils->moves.ra != 0 && utils->moves.rb != 0)
		{
			utils->moves.ra--;
			utils->moves.rb--;
			utils->moves.rr++;
		}
		while(utils->moves.rra != 0 && utils->moves.rrb != 0)
		{
			utils->moves.rra--;
			utils->moves.rrb--;
			utils->moves.rrr++;
		}
		while(utils->moves.sa != 0 && utils->moves.sb != 0)
		{
			utils->moves.sa--;
			utils->moves.sb--;
			utils->moves.ss++;
		}
		utils->moves.pb++;
	}
	else
	{
		stack_b = search_min_than_node(stack_a, stack_b);
		count_put_my_node_on_top_b(stack_b, &utils->moves);
		count_put_my_node_on_top_a(stack_a, &utils->moves);
		while(utils->moves.ra != 0 && utils->moves.rb != 0)
		{
			utils->moves.ra--;
			utils->moves.rb--;
			utils->moves.rr++;
		}
		while(utils->moves.rra != 0 && utils->moves.rrb != 0)
		{
			utils->moves.rra--;
			utils->moves.rrb--;
			utils->moves.rrr++;
		}
		while(utils->moves.sa != 0 && utils->moves.sb != 0)
		{
			utils->moves.sa--;
			utils->moves.sb--;
			utils->moves.ss++;
		}
		utils->moves.pb++;
	}
	if (count_num_moves(&utils->moves) < utils->countmovesofnode)
	{
		copy_moves(&utils->finalmoves, &utils->moves);
		utils->countmovesofnode = count_num_moves(&utils->moves);
	}
	reset_moves(&utils->moves);
}

void	sorting10(t_listlink *stack_a, t_listlink *stack_b)
{
	t_utils utils;
	int	nodes_a;

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
		{
			count_moves_node(stack_a, stack_b, &utils);
			stack_a = stack_a->next;
		}
		count_moves_node(stack_a, stack_b, &utils);
		exec_moves(utils.finalmoves, stack_a, stack_b);
		pb(stack_a, stack_b, 1);
		stack_a = stack_a->next;
		utils.nodes_b = move_on_first(stack_b)->before->index;
		nodes_a = move_on_first(stack_a)->before->index;
		utils.countmovesofnode = 999999;
	}
	sorting5(stack_a, stack_b);
}
