/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:51:14 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/31 18:01:13 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting3(t_listlink *stack_a)
{
	stack_a = move_on_first(stack_a);
	// pb(stack_a, stack_b, 1);
	// stack_a = stack_a->next;
	// pb(stack_a, stack_b, 1);
	// stack_a = stack_a->next;
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
				sa(stack_a, 1);
			else
				ra(stack_a, 1);
		}
	}
}

void	sorting5(t_listlink *stack_a, t_listlink *stack_b)
{
	int			nodes;
	t_listlink	*tmp;
	int			flag;
	int			content;

	content = 0;
	flag = 0;
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	pb(stack_a, stack_b, 1);
	stack_a = stack_a->next;
	stack_a = move_on_first(stack_a);
	stack_b = move_on_first(stack_b);
	nodes = stack_a->before->index;
	sorting3(stack_a);
	tmp = stack_b;
	while (stack_a->index != nodes)
	{
		if (stack_b->content < stack_a->content)
		{
			flag++;
			if (flag)
				tmp = stack_a;
			if (tmp->content > stack_a->content)
				tmp = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (stack_b->content < stack_a->content)
	{
		flag++;
		if (flag)
			tmp = stack_a;
		if (tmp->content > stack_a->content)
			tmp = stack_a;
	}
	if (tmp->content == stack_b->content)
	{
		//gestire il caso in cui il numero é il nuovo massimo
		//bisogna mettere il nuovo massimo sopra il minimo dello stack_a
		//bisogna quindi trovare il minimo
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
