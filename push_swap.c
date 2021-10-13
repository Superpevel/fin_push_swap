/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:33:12 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 16:19:32 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operations(t_oper *oper)
{
	while (oper != NULL)
	{
		ft_putendl_fd(oper->data, 1);
		oper = oper->next;
	}
}

int	ft_sort_asc(t_stack **a, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if ((*a)->n > (*a)->next->n)
		{
			add_oper(oper, swap(*a, 1));
			add_oper(oper, rotate(a, 1));
		}
		else
			add_oper(oper, rotate(a, 1));
	}
	while (++len < 3)
	{
		add_oper(oper, revrotate(a, 1));
		if ((*a)->n > (*a)->n)
			add_oper(oper, swap(*a, 1));
	}
	if ((*a)->n > (*a)->next->n)
		add_oper(oper, swap(*a, 1));
	return (0);
}

int	ft_sort_desc(t_stack **b, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if ((*b)->n < (*b)->next->n)
		{
			add_oper(oper, swap(*b, 2));
			add_oper(oper, rotate(b, 2));
		}
		else
			add_oper(oper, rotate(b, 2));
	}
	while (++len < 3)
	{
		add_oper(oper, revrotate(b, 2));
		if ((*b)->n < (*b)->n)
			add_oper(oper, swap(*b, 2));
	}
	if ((*b)->n < (*b)->next->n)
		add_oper(oper, swap(*b, 2));
	return (0);
}

char	**get_ac(int ac, char **av)
{
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		++av;
	return (av);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_oper		*oper;

	if (ac > 1)
	{
		av = get_ac(ac, av);
		if (!check_input(av))
		{
			ft_putendl_fd(ERROR, 1);
			exit(0);
		}
		fill_stack(&a, av);
		if (is_sorted(a) && !(b))
		{
			clear_memory(&a, &b);
			return (0);
		}
		sort_stack_a(&a, &b, stack_len(a), &oper);
		optim_operations(&oper);
		print_operations(oper);
		remove_oper(&oper);
		clear_memory(&a, &b);
	}
	return (0);
}
