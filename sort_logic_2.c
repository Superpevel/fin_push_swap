/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:55 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 15:47:33 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_push(t_stack *head, int id, int len, int pivot)
{
	t_stack	*ptr;

	ptr = head;
	while (len--)
	{
		if (id == 1 && ptr->n < pivot)
			return (1);
		else if (id == 2 && ptr->n > pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	backtrack_stack_a(t_stack **a, int r, t_oper **oper)
{
	if (r > stack_len(*a) / 2)
		while (stack_len(*a) - r++ > 0)
			add_oper(oper, rotate(a, 1));
	else
		while (r--)
			add_oper(oper, revrotate(a, 1));
}
