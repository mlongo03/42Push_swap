/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:34:15 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/30 19:26:45 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_listlink *stack_a, int flag)
{
	int	tmp1;

	tmp1 = 0;
	if (stack_a)
	{
		while (stack_a->index != 1)
			stack_a = stack_a->next;
		tmp1 = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp1;
		if (flag)
			write(1, "sa\n", 3);
	}
}

void	sb(t_listlink *stack_b, int flag)
{
	int	tmp1;

	tmp1 = 0;
	if (stack_b)
	{
		while (stack_b->index != 1)
			stack_b = stack_b->next;
		tmp1 = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp1;
		if (flag)
			write(1, "sb\n", 3);
	}
}

void	ss(t_listlink *stack_a, t_listlink *stack_b)
{
	if (stack_a || stack_b)
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
		write(1, "ss\n", 3);
	}
}

void	pa(t_listlink *stack_a, t_listlink *stack_b, int flag)
{
	t_listlink	*helper;
	t_listlink	*tmp;

	if (stack_a)
	{
		stack_a = move_on_first(stack_a);
		stack_b = move_on_first(stack_b);
		helper = ft_lstnew(0, stack_a->before->index + 1);
		stack_a->before->next = NULL;
		stack_a->before = NULL;
		ft_lstadd_back(&stack_a, helper);
		stack_a->before = ft_lstlast(stack_a);
		ft_lstlast(stack_a)->next = stack_a;
		rra(stack_a, 0);
		stack_a = move_on_first(stack_a);
		stack_a->content = stack_b->content;
		rb(stack_b, 0);
		stack_b = move_on_first(stack_b);
		tmp = stack_b->before;
		stack_b->before->before->next = stack_b;
		stack_b->before = stack_b->before->before;
		free(tmp);
		if (flag)
			write(1, "pa\n", 3);
	}
}

void	pb(t_listlink *stack_a, t_listlink *stack_b, int flag)
{
	t_listlink	*helper;
	t_listlink	*tmp;

	if (stack_b)
	{
		stack_b = move_on_first(stack_b);
		stack_a = move_on_first(stack_a);
		helper = ft_lstnew(0, stack_b->before->index + 1);
		stack_b->before->next = NULL;
		stack_b->before = NULL;
		ft_lstadd_back(&stack_b, helper);
		stack_b->before = ft_lstlast(stack_b);
		ft_lstlast(stack_b)->next = stack_b;
		rra(stack_b, 0);
		stack_b = move_on_first(stack_b);
		stack_b->content = stack_a->content;
		rb(stack_a, 0);
		stack_a = move_on_first(stack_a);
		tmp = stack_a->before;
		stack_a->before->before->next = stack_a;
		stack_a->before = stack_a->before->before;
		free(tmp);
		if (flag)
			write(1, "pb\n", 3);
	}
}
