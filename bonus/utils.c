/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:35:14 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 17:11:25 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_listlink	*move_on_first(t_listlink *stack)
{
	while (stack->index != 1)
		stack = stack->next;
	return (stack);
}

void	ft_error(void)
{
	ft_printf("Error");
	exit(1);
}

void	ft_free1(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	delete_list(t_listlink *stack_a)
{
	t_listlink	*tmp;

	while (stack_a->index != 1)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	free(stack_a);
}

void	ft_error2(char **helper, t_listlink *stack_a, int flag)
{
	if (flag == 1)
	{
		(void)stack_a;
		ft_free1(helper);
	}
	else
	{
		delete_list(stack_a);
		ft_free1(helper);
	}
	ft_printf("Error");
	exit(1);
}
