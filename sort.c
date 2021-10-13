/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:33:03 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 16:15:47 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a_onplace(t_stack **a, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*a)->n;
	y = get_y(len, a);
	z = get_z(len, a);
	if (x > y && y > z)
	{
		add_oper(oper, swap(*a, 1));
		add_oper(oper, revrotate(a, 1));
	}
	else if (x > z && z > y)
		add_oper(oper, rotate(a, 1));
	else if (z > x && x > y)
		add_oper(oper, swap(*a, 1));
	else if (y > z && z > x)
	{
		add_oper(oper, revrotate(a, 1));
		add_oper(oper, swap(*a, 1));
	}
	else if (y > x && x > z)
		add_oper(oper, revrotate(a, 1));
}

int	ft_sort_a(t_stack **a, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*a)->n;
	y = get_y(len, a);
	z = get_z(len, a);
	if (len == 1)
		return (0);
	else if (len == 2 && x > y)
		add_oper(oper, swap(*a, 1));
	else if (stack_len(*a) == 3 && len == 3)
		ft_sort_a_onplace(a, len, oper);
	else if (len == 3)
		ft_sort_asc(a, len, oper);
	return (0);
}
