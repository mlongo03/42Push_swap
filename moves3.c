/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:48:14 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 11:26:45 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_listlink *stack_a, t_listlink *stack_b)
{
	rrb(stack_b, 0);
	rra(stack_a, 0);
	write(1, "rrr\n", 4);
}

void	pa2(t_listlink **stack_a, t_listlink *stack_b, t_listlink **helper)
{
	if ((*stack_a)->next == NULL && (*stack_a)->before == NULL)
	{
		(*stack_a)->content = stack_b->content;
		(*stack_a)->next = *stack_a;
		(*stack_a)->before = *stack_a;
	}
	else
	{
		*stack_a = move_on_first(*stack_a);
		*helper = ft_lstnew(0, (*stack_a)->before->index + 1);
		(*stack_a)->before->next = NULL;
		(*stack_a)->before = NULL;
		ft_lstadd_back(stack_a, *helper);
		(*stack_a)->before = ft_lstlast(*stack_a);
		ft_lstlast(*stack_a)->next = *stack_a;
		rra(*stack_a, 0);
		*stack_a = move_on_first(*stack_a);
		(*stack_a)->content = stack_b->content;
	}
}

void	pa(t_listlink *stack_a, t_listlink *stack_b, int flag)
{
	t_listlink	*helper;
	t_listlink	*tmp;

	if (stack_b->next != NULL && stack_b->before != NULL)
	{
		stack_b = move_on_first(stack_b);
		pa2(&stack_a, stack_b, &helper);
		rb(stack_b, 0);
		stack_b = move_on_first(stack_b);
		if (stack_b->next->index == 1)
		{
			stack_b->next = NULL;
			stack_b->before = NULL;
		}
		else
		{
			tmp = stack_b->before;
			stack_b->before->before->next = stack_b;
			stack_b->before = stack_b->before->before;
			free(tmp);
		}
		if (flag)
			write(1, "pa\n", 3);
	}
}

void	pb2(t_listlink **stack_b, t_listlink *stack_a, t_listlink **helper)
{
	if ((*stack_b)->next == NULL && (*stack_b)->before == NULL)
	{
		(*stack_b)->content = stack_a->content;
		(*stack_b)->next = *stack_b;
		(*stack_b)->before = *stack_b;
	}
	else
	{
		*stack_b = move_on_first(*stack_b);
		*helper = ft_lstnew(0, (*stack_b)->before->index + 1);
		(*stack_b)->before->next = NULL;
		(*stack_b)->before = NULL;
		ft_lstadd_back(stack_b, *helper);
		(*stack_b)->before = ft_lstlast(*stack_b);
		ft_lstlast(*stack_b)->next = *stack_b;
		rra(*stack_b, 0);
		*stack_b = move_on_first(*stack_b);
		(*stack_b)->content = stack_a->content;
	}
}

void	pb(t_listlink *stack_a, t_listlink *stack_b, int flag)
{
	t_listlink	*helper;
	t_listlink	*tmp;

	if (stack_a->next != NULL && stack_a->before != NULL)
	{
		stack_a = move_on_first(stack_a);
		pb2(&stack_b, stack_a, &helper);
		ra(stack_a, 0);
		stack_a = move_on_first(stack_a);
		if (stack_a->next->index == 1)
		{
			stack_a->next = NULL;
			stack_a->before = NULL;
		}
		else
		{
			tmp = stack_a->before;
			stack_a->before->before->next = stack_a;
			stack_a->before = stack_a->before->before;
			free(tmp);
		}
		if (flag)
			write(1, "pb\n", 3);
	}
}
