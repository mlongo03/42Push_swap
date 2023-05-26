/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:14:32 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/26 15:34:41 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_listlink	*ft_lstnew(void *content, int index)
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
