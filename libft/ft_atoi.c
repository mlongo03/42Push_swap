/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:12:16 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/24 19:21:39 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

int static	ft_sign(char c)
{
	return (c == '-' || c == '+');
}

int static	ft_spaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

int	ft_atoi(const char *nptr)
{
	char	*p;
	int		s;
	long	r;

	p = (char *) nptr;
	s = 1;
	r = 0;
	while (ft_spaces(*p))
		p++;
	if (ft_sign(*p))
	{
		if (*p == '-')
			s = -1;
		p++;
	}
	while (ft_isdigit((int) *p))
	{
		r *= 10;
		r += *(p++) - 48;
	}
	if ((r * s) > INT_MAX || (r * s) < INT_MIN)
	{
		printf("Error\n");
		exit (1);
	}
	return (r * s);
}
