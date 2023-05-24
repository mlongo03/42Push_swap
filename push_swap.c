/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:15:50 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/24 19:21:17 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(char **argv, int argc)
{
	int seen[argc - 1];
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		seen[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = i;
		while (j < argc - 1)
		{
			if (seen[i] == seen[j + 1])
			{
				ft_printf("Error");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_int(char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] < 49 || argv[i][j] > 57)
			{
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	// t_list stack_a;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	check_int(argv, argc);
	check_duplicates(argv, argc);
	return (0);
}
