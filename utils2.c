/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:33:57 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/31 12:52:21 by mlongo           ###   ########.fr       */
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
