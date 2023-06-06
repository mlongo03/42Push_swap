/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:11:49 by mstocche          #+#    #+#             */
/*   Updated: 2023/06/06 17:46:46 by mlongo           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char		*tmp;
	t_listlink	*stack_a;
	t_listlink	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = create_stack_a(argv + 1, argc - 1);
	argc = stack_a->before->index + 1;
	check_duplicates(stack_a, argc);
	stack_b = ft_lstnew(90, 1);
	stack_b->before = NULL;
	stack_b->next = NULL;
	tmp = get_next_line(0);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp, "ra\n", 3) == 0 && ft_strlen(tmp) == 3)
			ra(stack_a);
		else if (ft_strncmp(tmp, "rb\n", 3) == 0 && ft_strlen(tmp) == 3)
			rb(stack_b);
		else if (ft_strncmp(tmp, "rr\n", 3) == 0 && ft_strlen(tmp) == 3)
			rr(stack_a, stack_b);
		else if (ft_strncmp(tmp, "rra\n", 4) == 0 && ft_strlen(tmp) == 4)
			rra(stack_a);
		else if (ft_strncmp(tmp, "rrb\n", 4) == 0 && ft_strlen(tmp) == 4)
			rrb(stack_b);
		else if (ft_strncmp(tmp, "rrr\n", 4) == 0 && ft_strlen(tmp) == 4)
			rrr(stack_a, stack_b);
		else if (ft_strncmp(tmp, "sa\n", 3) == 0 && ft_strlen(tmp) == 3)
			sa(stack_a);
		else if (ft_strncmp(tmp, "sb\n", 3) == 0 && ft_strlen(tmp) == 3)
			sb(stack_b);
		else if (ft_strncmp(tmp, "ss\n", 3) == 0 && ft_strlen(tmp) == 3)
			ss(stack_a, stack_b);
		else if (ft_strncmp(tmp, "pa\n", 3) == 0 && ft_strlen(tmp) == 3)
		{
			pa(stack_a, stack_b);
			if (stack_b->next != NULL)
				stack_b = stack_b->next;
		}
		else if (ft_strncmp(tmp, "pb\n", 3) == 0 && ft_strlen(tmp) == 3)
		{
			pb(stack_a, stack_b);
			stack_a = stack_a->next;
		}
		else
		{
			write(1, "KO\n", 3);
			free(tmp);
			stack_a = move_on_first(stack_a);
			delete_list(stack_a->next);
			if (stack_b->next == NULL)
				free(stack_b);
			else
				delete_list(stack_b->next);
			return (0);
		}
		free(tmp);
		tmp = get_next_line(0);
	}
	free(tmp);
	stack_a = move_on_first(stack_a);
	while (stack_a->index != move_on_first(stack_a)->before->index)
	{
		if (stack_a->content > stack_a->next->content)
		{
			write(1, "KO\n", 3);
			stack_a = move_on_first(stack_a);
			delete_list(stack_a->next);
			if (stack_b->next == NULL)
				free(stack_b);
			else
				delete_list(stack_b->next);
			return (0);
		}
		stack_a = stack_a->next;
	}
	if (stack_b->next == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_a = move_on_first(stack_a);
	delete_list(stack_a->next);
	if (stack_b->next == NULL)
		free(stack_b);
	else
		delete_list(stack_b->next);
	return (0);
}
