/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:14:32 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/27 14:55:10 by alessiolong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_listlink	*ft_lstnew(int content, int index)
{
	t_listlink	*res;

	res = (t_listlink *) malloc(sizeof(t_listlink));
	if (res == NULL)
		return (NULL);
	res->content = content;
	res->next = NULL;
	res->before = NULL;
	res->index = index;
	return (res);
}
