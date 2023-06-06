/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstocche <mstocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:39:41 by mstocche          #+#    #+#             */
/*   Updated: 2023/06/06 18:09:33 by mstocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_create
{
	char		**helper;
	int			i;
	int			j;
	int			index;
	t_listlink	*tmp;
}	t_create;

void		ft_error(void);
t_listlink	*move_on_first(t_listlink *stack);
void		ft_free1(char **split);
void		delete_list(t_listlink *stack_a);
void		ft_error2(char **helper, t_listlink *stack_a, int flag);
void		sa(t_listlink *stack_a);
void		sb(t_listlink *stack_b);
void		ss(t_listlink *stack_a, t_listlink *stack_b);
void		pa(t_listlink *stack_a, t_listlink *stack_b);
void		pb(t_listlink *stack_a, t_listlink *stack_b);
void		ra(t_listlink *stack_a);
void		rb(t_listlink *stack_b);
void		rr(t_listlink *stack_a, t_listlink *stack_b);
void		rra(t_listlink *stack_a);
void		rrb(t_listlink *stack_b);
void		rrr(t_listlink *stack_a, t_listlink *stack_b);
void		check_duplicates(t_listlink *stack_a, int argc);
void		check_int(char **helper, t_listlink *stack_a, int flag);
void		create_stack_a2(t_listlink **stack_a, char **argv,
				t_create *utils, int argc);
t_listlink	*create_stack_a(char **argv, int argc);

#endif
