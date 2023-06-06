/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:07:23 by mstocche          #+#    #+#             */
/*   Updated: 2023/06/06 18:55:19 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/checker.h"

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
					ft_error2(helper, stack_a, flag);
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
