/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:15:50 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/31 16:32:40 by mlongo           ###   ########.fr       */
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
		seen[i - 1] = stack_a->content;
		i++;
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

t_listlink	*create_stack_a(char **argv, int argc)
{
	t_listlink	*stack_a;
	t_listlink	*tmp;
	char		**helper;
	int			i;
	int			j;
	int			index;

	i = 0;
	j = 0;
	index = 0;
	helper = ft_split(argv[i++], ' ');
	check_int(helper, NULL, 1);
	stack_a = ft_lstnew(ft_atoi(helper[j]), j + 1);
	j++;
	while (helper[j])
	{
		tmp = ft_lstnew(ft_atoi(helper[j]), j + 1);
		ft_lstadd_back(&stack_a, tmp);
		j++;
	}
	ft_free1(helper);
	index = j;
	while (i < argc)
	{
		helper = ft_split(argv[i++], ' ');
		check_int(helper, stack_a, 2);
		j = 0;
		while (helper[j])
		{
			tmp = ft_lstnew(ft_atoi(helper[j]), index + 1);
			ft_lstadd_back(&stack_a, tmp);
			j++;
			index++;
		}
		ft_free1(helper);
	}
	stack_a->before = ft_lstlast(stack_a);
	ft_lstlast(stack_a)->next = stack_a;
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
	printf("PRINT STACK_A BEFORE\n");
	print_nodes(stack_a, argc - 1);
	stack_b = ft_lstnew(90, 1);
	// ft_lstadd_back(&stack_b, ft_lstnew(1000, 2));
	// ft_lstadd_back(&stack_b, ft_lstnew(2000, 3));
	// stack_b->before = ft_lstlast(stack_b);
	// ft_lstlast(stack_b)->next = stack_b;
	stack_b->before = NULL;
	stack_b->next = NULL;
	// printf("PRINT STACK_B BEFORE\n");
	// print_nodes(stack_b, 1);
	sorting5(stack_a, stack_b);
	// pa(stack_a, stack_b, 1);
	// argc++;
	// while (stack_a->index != 1)
	// 	stack_a = stack_a->next;
	// while (stack_b->index != 1)
	// 	stack_b = stack_b->next;
	// printf("PRINT STACK_B AFTER\n");
	// print_nodes(stack_b, 1);
	printf("PRINT STACK_A AFTER\n");
	print_nodes(stack_a, 4);
	// pb(stack_a, stack_b, 1);
	// argc--;
	// stack_a = move_on_first(stack_a->next);
	// stack_b = move_on_first(stack_b);
	// printf("PRINT STACK_B AFTER\n");
	// print_nodes(stack_b, 1);
	// printf("PRINT STACK_A AFTER\n");
	// print_nodes(stack_a, argc - 1);
	while (stack_a->index != 1)
		stack_a = stack_a->next;
	delete_list(stack_a->next);
	while (stack_b->index != 1)
		stack_b = stack_b->next;
	delete_list(stack_b->next);
	return (0);
}
