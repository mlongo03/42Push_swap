/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:33:57 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/07 11:22:07 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nodes(t_listlink *stack, int j)
{
	while (stack->index != j)
	{
		printf("content : %d\nindex : %d\n", stack->content, stack->index);
		stack = stack->next;
	}
	if (stack->next == NULL)
		printf("stack é vuoto\n");
	else
	{
		printf("content : %d\nindex : %d\n", stack->content, stack->index);
	}
}

void	check_order(t_listlink **stack_a, t_listlink **stack_b)
{
	while ((*stack_a)->index != move_on_first(*stack_a)->before->index)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			return ;
		*stack_a = (*stack_a)->next;
	}
	finalfree(stack_a, stack_b);
}

void	finalfree(t_listlink **stack_a, t_listlink **stack_b)
{
	*stack_a = move_on_first(*stack_a);
	delete_list((*stack_a)->next);
	*stack_b = move_on_first(*stack_b);
	if ((*stack_b)->next == NULL)
		free(*stack_b);
	else
		delete_list((*stack_b)->next);
	exit (1);
}
