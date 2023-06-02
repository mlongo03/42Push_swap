/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:51:14 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/02 12:33:59 by alessiolong      ###   ########.fr       */
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

void	count_put_my_node_on_top_a(t_listlink *stack, t_moves *moves)
{
	int content;
	int	nodes;
	int	countra;
	int	countrra;

	countra = 0;
	countrra = 0;
	nodes = move_on_first(stack)->before->index;
	printf("i nodi sono %d\n", nodes);
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
	nodes = move_on_first(stack)->before->content;
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

void	count_put_max_on_top(t_listlink *stack, t_moves *moves)
{
	t_listlink	*tmp;
	int	nodes;
	int	content;
	int	countra;
	int	countrra;

	countra = 0;
	countrra = 0;
	content = 0;
	stack = move_on_first(stack);
	nodes = stack->before->index;
	if (stack->content > stack->next->content)
	{
		tmp = stack;
		content = stack->content;
	}
	else
	{
		tmp = stack->next;
		content = stack->next->content;
	}
	while (stack->index != nodes)
	{
		if (stack->content > content)
		{
			tmp = stack;
			content = stack->content;
		}
		stack = stack->next;
	}
	if (stack->content > content)
	{
		tmp = stack;
		content = stack->content;
	}
	if (nodes % 2 != 0)
		nodes = nodes + 1;
	if (tmp->index <= (nodes / 2))
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
			// printf("before\nfirst content stack_b : %d\n", move_on_first(stack)->content);
			rrb(stack, 0);
			// printf("after\nfirst content stack_b : %d\n", move_on_first(stack)->content);
		}
	}
	while (countra--)
		rrb(stack, 0);
	while (countrra--)
		rb(stack, 0);
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
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	stack_a = move_on_first(stack_a);
	stack_b = move_on_first(stack_b);
	sorting3(stack_a);
	sorting_push(move_on_first(stack_a), move_on_first(stack_b));
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

void	count_moves_node(t_listlink *stack_a, t_listlink *stack_b, t_moves *moves, int nodes_b, int *countmovesofnode, t_listlink *mvp)
{
	int	num_max;
	int	num_min;

	num_max = 0;
	num_min = 0;
	stack_b = move_on_first(stack_b);
	while(stack_b->index != nodes_b)
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
	if (num_min == nodes_b || num_max == nodes_b)
	{
		//siamo nel caso in cui il numero é il nuovo massimo o il nuovo minimo
		//quindi contare le mosse per metterlo sopra al vecchio massimo
		count_put_my_node_on_top_a(stack_a, moves);
		count_put_max_on_top(stack_b, moves);
		printf("BEFORE\nnum mosse ra: %d\nnum mosse rb: %d\n", moves->ra, moves->rb);
		printf("num mosse rra: %d\nnum mosse rrb: %d\n", moves->rra, moves->rrb);
		printf("num mosse rr: %d\nnum mosse rrr: %d\n", moves->rr, moves->rrr);
		while(((moves->ra + moves->rb) % 2 == 0) && (moves->ra != 0 && moves->rb != 0))
		{
			// printf("okkkkkkkkkkkk\n");
			moves->ra--;
			moves->rb--;
			moves->rr++;
		}
		while(((moves->rra + moves->rrb) % 2 == 0) && (moves->rra != 0 && moves->rrb != 0))
		{
			// printf("okkkkkkkkkkkk\n");
			moves->rra--;
			moves->rrb--;
			moves->rrr++;
		}
		while(((moves->sa + moves->sb) % 2 == 0) && (moves->sa != 0 && moves->sb != 0))
		{
			// printf("okkkkkkkkkkkk\n");
			moves->sa--;
			moves->sb--;
			moves->ss++;
		}
		//nel caso in cui ho 2 mosse uguali per entrambi gli stack ne conto solo una
		moves->pb++;
	}
	else
	{
		//siamo nel caso in cui il numero é intermedio
		//quindi contare le mosse per metterlo sopra al numero minore che gli si avvicina di piú
		stack_b = search_min_than_node(stack_a, stack_b);
		count_put_my_node_on_top_b(stack_b, moves);
		count_put_my_node_on_top_a(stack_a, moves);
		printf("BEFORE\nnum mosse ra: %d\nnum mosse rb: %d\n", moves->ra, moves->rb);
		printf("num mosse rra: %d\nnum mosse rrb: %d\n", moves->rra, moves->rrb);
		printf("num mosse rr: %d\nnum mosse rrr: %d\n", moves->rr, moves->rrr);
		while(((moves->ra + moves->rb) % 2 == 0) && (moves->ra != 0 && moves->rb != 0))
		{
			// printf("okkkkkkkkkkkk\n");
			moves->ra--;
			moves->rb--;
			moves->rr++;
		}
		while(((moves->rra + moves->rrb) % 2 == 0) && (moves->rra != 0 && moves->rrb != 0))
		{
			// printf("okkkkkkkkkkkk\n");
			moves->rra--;
			moves->rrb--;
			moves->rrr++;
		}
		while(((moves->sa + moves->sb) % 2 == 0) && (moves->sa != 0 && moves->sb != 0))
		{
			// printf("okkkkkkkkkkkk\n");
			moves->sa--;
			moves->sb--;
			moves->ss++;
		}
		moves->pb++;
	}
	printf("AFTER\nnum mosse ra: %d\nnum mosse rb: %d\n", moves->ra, moves->rb);
	printf("num mosse rra: %d\nnum mosse rrb: %d\n", moves->rra, moves->rrb);
	printf("num mosse rr: %d\nnum mosse rrr: %d\n", moves->rr, moves->rrr);
	printf("num mosse : %d\n", count_num_moves(moves));
	if (count_num_moves(moves) < *countmovesofnode) //attuale minore di precedente
	{
		*countmovesofnode = count_num_moves(moves);
		mvp = stack_a;
	}
	reset_moves(moves);
}

void	sorting10(t_listlink *stack_a, t_listlink *stack_b)
{
	t_moves	moves;
	int	nodes_b;
	int	nodes_a;
	t_listlink	*mvp;
	int	countmovesofnode;

	mvp = stack_a;
	countmovesofnode = 999999;
	reset_moves(&moves);
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	nodes_b = move_on_first(stack_b)->before->index;
	nodes_a = move_on_first(stack_a)->before->index;
	// printf("nodi a: %d\n", nodes_a);
	stack_a = move_on_first(stack_a);
	while (stack_a->index != nodes_a)
	{
		count_moves_node(stack_a, stack_b, &moves, nodes_b, &countmovesofnode, mvp);
		stack_a = stack_a->next;
	}
	printf("il mio nodo piú economico é quello con contenuto : %d\nindex : %d\ne ha mosse : %d\n", mvp->content, mvp->index, countmovesofnode);
}
