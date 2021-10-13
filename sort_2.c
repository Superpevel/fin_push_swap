/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:14:11 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 16:14:12 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_y(int len, t_stack **b)
{
	int	y;

	if (len >= 2)
		y = (*b)->next->n;
	else
		y = 0;
	return (y);
}

int	get_z(int len, t_stack **b)
{
	int	z;

	if (len == 3)
		z = (*b)->next->next->n;
	else
		z = 0;
	return (z);
}

void	ft_sort_b_onplace(t_stack **b, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*b)->n;
	y = get_y(len, b);
	z = get_z(len, b);
	if (x < y && y < z)
	{
		add_oper(oper, swap(*b, 2));
		add_oper(oper, revrotate(b, 2));
	}
	else if (x < z && z < y)
		add_oper(oper, rotate(b, 2));
	else if (z < x && x < y)
		add_oper(oper, swap(*b, 2));
	else if (y < z && z < x)
	{
		add_oper(oper, revrotate(b, 2));
		add_oper(oper, swap(*b, 2));
	}
	else if (y < x && x < z)
		add_oper(oper, revrotate(b, 2));
}

int	ft_sort_b(t_stack **b, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*b)->n;
	if (len >= 2)
		y = (*b)->next->n;
	else
		y = 0;
	if (len == 3)
		z = (*b)->next->next->n;
	else
		z = 0;
	if (len == 1)
		return (0);
	else if (len == 2 && x < y)
		add_oper(oper, swap(*b, 2));
	else if (stack_len(*b) == 3 && len == 3)
		ft_sort_b_onplace(b, len, oper);
	else if (len == 3)
		ft_sort_desc(b, len, oper);
	return (0);
}
