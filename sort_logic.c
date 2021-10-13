/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:33:07 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 15:49:37 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_ad_b(t_stack **a, t_stack **b, int p, t_oper **oper)
{
	while (p--)
		add_oper(oper, push(a, b, 1));
	return (1);
}

int	sort_stack_a(t_stack **a, t_stack **b, int len, t_oper **oper)
{
	int		pivot;
	int		p;
	int		r;
	int		i;

	r = 0;
	i = 0;
	p = 0;
	if (len <= 3)
		return (ft_sort_a(a, len, oper));
	pivot = ft_pivot(*a, len);
	while (need_push(*a, 1, len - i, pivot) && i++ < len)
	{
		if ((*a)->n < pivot && ++p)
			add_oper(oper, push(b, a, 2));
		else
		{
			add_oper(oper, rotate(a, 1));
			r++;
		}
	}
	backtrack_stack_a(a, r, oper);
	sort_stack_a(a, b, len - p, oper);
	sort_stack_b(a, b, p, oper);
	return (op_ad_b(a, b, p, oper));
}

void	backtrack_stack_b(t_stack **b, int r, t_oper **oper)
{
	if (r > stack_len(*b) / 2)
		while (stack_len(*b) - r++ > 0)
			add_oper(oper, rotate(b, 2));
	else
		while (r--)
			add_oper(oper, revrotate(b, 2));
}

int	op_ad(t_stack **a, t_stack **b, int p, t_oper **oper)
{
	while (p--)
		add_oper(oper, push(b, a, 2));
	return (1);
}

int	sort_stack_b(t_stack **a, t_stack **b, int len, t_oper **oper)
{
	int		pivot;
	int		p;
	int		r;
	int		i;

	r = 0;
	i = 0;
	p = 0;
	if (len <= 3)
		return (ft_sort_b(b, len, oper));
	pivot = ft_pivot(*b, len);
	while (need_push(*b, 2, len - i, pivot) && i++ < len)
	{
		if ((*b)->n > pivot && ++p)
			add_oper(oper, push(a, b, 1));
		else
		{
			add_oper(oper, rotate(b, 2));
			r++;
		}
	}
	sort_stack_a(a, b, p, oper);
	backtrack_stack_b(b, r, oper);
	sort_stack_b(a, b, len - p, oper);
	return (op_ad(a, b, p, oper));
}
