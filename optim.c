/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:33:17 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 18:55:06 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optim_s2(t_oper **oper, int *flag, t_oper **tmp)
{
	t_oper	*prev;
	t_oper	*first;
	t_oper	*second;

	while ((*tmp)->next && (*tmp)->next->next)
	{
		prev = *tmp;
		first = (*tmp)->next;
		second = first->next;
		if (ft_str_equal(first->data, "sb")
			&& ft_str_equal(second->data, "sb"))
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

void	optim_sbsb(t_oper **oper, int *flag, int *all)
{
	t_oper	*tmp;

	while (1)
	{
		*flag = 0;
		tmp = (*oper);
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}

void	optim_pbpa2(t_oper **oper, int *flag, t_oper **tmp, t_oper **prev)
{
	t_oper	*first;
	t_oper	*second;

	first = (*tmp)->next;
	second = first->next;
	if (ft_str_equal(first->data, "pb")
		&& ft_str_equal(second->data, "pa"))
	{
		*flag = 1;
		(*prev)->next = second->next;
		ft_strdel(&second->data);
		free(second);
		second = NULL;
		ft_strdel(&first->data);
		free(first);
		first = NULL;
		*tmp = (*prev)->next;
	}
	else
		*tmp = (*tmp)->next;
}

void	optim_pbpa1(t_oper **oper, int *flag, t_oper **tmp)
{
	t_oper	*prev;
	t_oper	*first;
	t_oper	*second;

	while ((*tmp)->next && (*tmp)->next->next)
	{
		prev = *tmp;
		first = (*tmp)->next;
		second = first->next;
		if (ft_str_equal(first->data, "pa") && ft_str_equal(second->data, "pb"))
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
		optim_pbpa2(oper, flag, tmp, &prev);
	}
}

void	optim_pbpa(t_oper **oper, int *flag, int *all)
{
	t_oper	*tmp;
	t_oper	*prev;
	t_oper	*first;
	t_oper	*second;

	while (1)
	{
		*flag = 0;
		tmp = (*oper);
		optim_pbpa1(oper, flag, &tmp);
		if (*flag == 0)
			break ;
		else
			*all = 1;
	}
}
