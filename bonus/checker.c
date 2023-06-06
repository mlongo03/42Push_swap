/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstocche <mstocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:11:49 by mstocche          #+#    #+#             */
/*   Updated: 2023/06/06 18:34:17 by mstocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/checker.h"

void	handle_ko(t_listlink **stack_a, t_listlink *stack_b)
{
	*stack_a = move_on_first(*stack_a);
	delete_list((*stack_a)->next);
	if (stack_b->next == NULL)
		free(stack_b);
	else
		delete_list(stack_b->next);
	exit (1);
}

void	check_moves2(t_listlink *stack_a, t_listlink *stack_b, char **tmp)
{
	if (ft_strncmp(*tmp, "pa\n", 3) == 0 && ft_strlen(*tmp) == 3)
	{
		pa(stack_a, stack_b);
		if (stack_b->next != NULL)
			stack_b = stack_b->next;
	}
	else if (ft_strncmp(*tmp, "pb\n", 3) == 0 && ft_strlen(*tmp) == 3)
	{
		pb(stack_a, stack_b);
		stack_a = stack_a->next;
	}
	else
	{
		write(1, "KO\n", 3);
		free(*tmp);
		handle_ko(&stack_a, stack_b);
	}	
}

void	check_moves(t_listlink *stack_a, t_listlink *stack_b, char **tmp)
{
	if (ft_strncmp(*tmp, "ra\n", 3) == 0 && ft_strlen(*tmp) == 3)
		ra(stack_a);
	else if (ft_strncmp(*tmp, "rb\n", 3) == 0 && ft_strlen(*tmp) == 3)
		rb(stack_b);
	else if (ft_strncmp(*tmp, "rr\n", 3) == 0 && ft_strlen(*tmp) == 3)
		rr(stack_a, stack_b);
	else if (ft_strncmp(*tmp, "rra\n", 4) == 0 && ft_strlen(*tmp) == 4)
		rra(stack_a);
	else if (ft_strncmp(*tmp, "rrb\n", 4) == 0 && ft_strlen(*tmp) == 4)
		rrb(stack_b);
	else if (ft_strncmp(*tmp, "rrr\n", 4) == 0 && ft_strlen(*tmp) == 4)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(*tmp, "sa\n", 3) == 0 && ft_strlen(*tmp) == 3)
		sa(stack_a);
	else if (ft_strncmp(*tmp, "sb\n", 3) == 0 && ft_strlen(*tmp) == 3)
		sb(stack_b);
	else if (ft_strncmp(*tmp, "ss\n", 3) == 0 && ft_strlen(*tmp) == 3)
		ss(stack_a, stack_b);
	else
		check_moves2(stack_a, stack_b, tmp);
	free(*tmp);
	*tmp = get_next_line(0);
}

void	main2(t_listlink **stack_a, t_listlink *stack_b)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		write(1, "KO\n", 3);
		handle_ko(stack_a, stack_b);
	}
	*stack_a = (*stack_a)->next;
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
		check_moves(stack_a, stack_b, &tmp);
	free(tmp);
	stack_a = move_on_first(stack_a);
	while (stack_a->index != move_on_first(stack_a)->before->index)
		main2(&stack_a, stack_b);
	if (stack_b->next == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	handle_ko(&stack_a, stack_b);
}
