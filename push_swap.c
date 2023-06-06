/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:15:50 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/06 11:31:38 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	check_duplicates(t_listlink *stack_a, int argc)
{
	int	*seen;
	int	i;
	int	j;

	i = 1;
	j = 0;
	seen = (int *)malloc((argc - 1) * sizeof(int));
	while (i < argc)
	{
		seen[i++ - 1] = stack_a->content;
		stack_a = stack_a->next;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = i;
		while (j < argc - 2)
		{
			if (seen[i] == seen[j + 1])
				ft_error();
			j++;
		}
		i++;
	}
	free(seen);
}

void	check_int(char **helper, t_listlink *stack_a, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (helper[i])
	{
		j = 0;
		while (helper[i][j])
		{
			if (helper[i][j] != '-' && helper[i][j] != '+')
				if (helper[i][j] < 48 || helper[i][j] > 57)
					ft_error1(helper, stack_a, flag);
			j++;
		}
		i++;
	}
}

void	create_stack_a2(t_listlink **stack_a, char **argv,
	t_create *utils, int argc)
{
	ft_free1(utils->helper);
	utils->index = utils->j;
	while (utils->i < argc)
	{
		utils->helper = ft_split(argv[utils->i++], ' ');
		check_int(utils->helper, *stack_a, 2);
		utils->j = 0;
		while (utils->helper[utils->j])
		{
			utils->tmp = ft_lstnew(ft_atoi(utils->helper[utils->j]),
					utils->index + 1);
			ft_lstadd_back(stack_a, utils->tmp);
			utils->j++;
			utils->index++;
		}
		ft_free1(utils->helper);
	}
	(*stack_a)->before = ft_lstlast(*stack_a);
	ft_lstlast(*stack_a)->next = *stack_a;
}

t_listlink	*create_stack_a(char **argv, int argc)
{
	t_listlink	*stack_a;
	t_create	utils;

	utils.i = 0;
	utils.j = 0;
	utils.index = 0;
	utils.helper = ft_split(argv[utils.i++], ' ');
	check_int(utils.helper, NULL, 1);
	stack_a = ft_lstnew(ft_atoi(utils.helper[utils.j]), utils.j + 1);
	utils.j++;
	while (utils.helper[utils.j])
	{
		utils.tmp = ft_lstnew(ft_atoi(utils.helper[utils.j]), utils.j + 1);
		ft_lstadd_back(&stack_a, utils.tmp);
		utils.j++;
	}
	create_stack_a2(&stack_a, argv, &utils, argc);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_listlink	*stack_a;
	t_listlink	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = create_stack_a(argv + 1, argc - 1);
	argc = stack_a->before->index + 1;
	check_duplicates(stack_a, argc);
	stack_b = ft_lstnew(90, 1);
	stack_b->before = NULL;
	stack_b->next = NULL;
	if (argc - 1 == 2)
		sorting2(stack_a);
	else if (argc - 1 == 4)
		sorting4(stack_a, stack_b);
	else
		sorting10(stack_a, stack_b);
	stack_a = move_on_first(stack_a);
	delete_list(stack_a->next);
	stack_b = move_on_first(stack_b);
	if (stack_b->next == NULL)
		free(stack_b);
	else
		delete_list(stack_b->next);
	return (0);
}
