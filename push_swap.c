#include "push_swap.h"

void	print_operations(t_oper *oper)
{
	while (oper != NULL)
	{
		ft_putendl_fd(oper->data, 1);
		oper = oper->next;
	}
}

int		ft_sort_asc(t_stack **a, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if ((*a)->n > (*a)->next->n)
		{
			add_oper(oper, SA);
			add_oper(oper, RA);
		}
		else
			add_oper(oper, RA);
	}
	while (++len < 3)
	{
		add_oper(oper, RRA);
		if ((*a)->n > (*a)->n)
			add_oper(oper, SA);
	}
	if ((*a)->n > (*a)->next->n)
		add_oper(oper, SA);
	return (0);
}

int		ft_sort_desc(t_stack **b, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if ((*b)->n < (*b)->next->n)
		{
			add_oper(oper, SB);
			add_oper(oper, RB);
		}
		else
			add_oper(oper, RB);
	}
	while (++len < 3)
	{
		add_oper(oper, RRB);
		if ((*b)->n < (*b)->n)
			add_oper(oper, SB);
	}
	if ((*b)->n < (*b)->next->n)
		add_oper(oper, SB);
	return (0);
}


int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_oper		*oper;

	if (ac > 1)
	{
		ac == 2 ? av = ft_split(av[1], ' ') : ++av;
		if (!check_input(av))
		{
			ft_putendl_fd(ERROR,1);
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

