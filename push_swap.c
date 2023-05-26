/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:15:50 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/26 18:06:11 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	ft_printf("Error");
	exit(1);
}

void	check_duplicates(t_listlink stack_a, int argc)
{
	int seen[argc - 1];
	int i;
	int j;
	int y;

	i = 1;
	j = 0;
	y = 0;
	while (i < argc - 1)
	{
		seen[i - 1] = ft_atoi((char *)stack_a.content);
		i++;
		stack_a = *stack_a.next;
	}
	while (seen[y])
	{
		ft_printf("%d\n", seen[y]);
		y++;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = i;
		while (j < argc - 1)
		{
			// ft_printf("seen[i] = %d\nseen[j + 1] = %d\n", seen[i], seen[j + 1]);
			if (seen[i] == seen[j + 1])
				ft_error();
			j++;
		}
		i++;
	}
}

// void	check_int(t_listlink stack_a, int argc)
// {
// 	int i;

// 	i = 1;
// 	while (stack_a.index != argc - 1)
// 	{
// 		while(*(char *)stack_a.content)
// 		{
// 			if (*(char *)stack_a.content != '-' && *(char *)stack_a.content != '+')
// 				if (*(char *)stack_a.content < 49 || *(char *)stack_a.content > 57)
// 					ft_error();
// 			stack_a.content++;
// 		}
// 		stack_a = *stack_a.next;
// 	}
// 	while(*(char *)stack_a.content)
// 	{
// 		if (*(char *)stack_a.content != '-' && *(char *)stack_a.content != '+')
// 			if (*(char *)stack_a.content < 49 || *(char *)stack_a.content > 57)
// 				ft_error();
// 		stack_a.content++;
// 	}
// }

void	check_int(char **helper)
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
				if (helper[i][j] < 49 || helper[i][j] > 57)
					ft_error();
			j++;
		}
		i++;
	}
}

t_listlink	*create_stack_a(char **argv, int argc)
{
	t_listlink 	*stack_a;
	t_listlink	*tmp;
	char		**helper;
	int			i;
	int			j;
	int			index;

	i = 0;
	j = 0;
	index = 0;
	helper = ft_split(argv[i++], ' ');
	check_int(helper);
	stack_a = ft_lstnew(helper[j], j + 1);
	j++;
	while (helper[j])
	{
		tmp = ft_lstnew(helper[j], j + 1);
		ft_lstadd_back(&stack_a, tmp);
		j++;
	}
	index = j;
	while (i < argc)
	{
		helper = ft_split(argv[i++], ' ');
		check_int(helper);
		j = 0;
		while (helper[j])
		{
			tmp = ft_lstnew(helper[j], index + 1);
			ft_lstadd_back(&stack_a, tmp);
			j++;
			index++;
		}
	}
	stack_a->before = ft_lstlast(stack_a);
	ft_lstlast(stack_a)->next = stack_a;
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_listlink *stack_a;

	if (argc == 1)
		return (1);
	stack_a = create_stack_a(argv + 1, argc - 1);
	check_duplicates(*stack_a, argc);
	// while(stack_a->index != argc - 1)
	// {
	// 	printf("%d\n%d\n", *(int *)(stack_a->content), stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// printf("%d\n%d\n", *(int *)(stack_a->content), stack_a->index);
	return (0);
}
