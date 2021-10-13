/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim_ssa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:52:34 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 18:54:52 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optim_s1(t_oper **oper, int *flag, t_oper **tmp)
{
	t_oper	*prev;
	t_oper	*first;
	t_oper	*second;

	while ((*tmp)->next && (*tmp)->next->next)
	{
		prev = *tmp;
		first = (*tmp)->next;
		second = first->next;
		if (ft_str_equal(first->data, "sa")
			&& ft_str_equal(second->data, "sa"))
		{
			*flag = 1;
			prev->next = second->next;
			ft_strdel(&second->data);
			free(second);
			second = NULL;
			ft_strdel(&first->data);
			free(first);
			first = NULL;
			*tmp = prev->next;
		}
		else
			*tmp = (*tmp)->next;
	}
}

void	optim_sasa(t_oper **oper, int *flag, int *all)
{
	t_oper	*tmp;

	while (1)
	{
		*flag = 0;
		tmp = (*oper);
		optim_s1(oper, flag, &tmp);
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}
