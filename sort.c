#include "push_swap.h"

void	ft_sort_a_onplace(t_stack **a, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*a)->n;
	y = (len >= 2) ? (*a)->next->n : 0;
	z = (len == 3) ? (*a)->next->next->n : 0;
	if (x > y && y > z)
	{
		add_oper(oper, swap(*a, 1));
		add_oper(oper, RRA);
	}
	else if (x > z && z > y)
		add_oper(oper, RA);
	else if (z > x && x > y)
		add_oper(oper, swap(*a, 1));
	else if (y > z && z > x)
	{
		add_oper(oper, RRA);
		add_oper(oper, swap(*a, 1));
	}
	else if (y > x && x > z)
		add_oper(oper, RRA);
}

int		ft_sort_a(t_stack **a, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*a)->n;
	y = (len >= 2) ? (*a)->next->n : 0;
	z = (len == 3) ? (*a)->next->next->n : 0;
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

void	ft_sort_b_onplace(t_stack **b, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*b)->n;
	y = (len >= 2) ? (*b)->next->n : 0;
	z = (len == 3) ? (*b)->next->next->n : 0;
	if (x < y && y < z)
	{
		add_oper(oper, SB);
		add_oper(oper, RRB);
	}
	else if (x < z && z < y)
		add_oper(oper, RB);
	else if (z < x && x < y)
		add_oper(oper, SB);
	else if (y < z && z < x)
	{
		add_oper(oper, RRB);
		add_oper(oper, SB);
	}
	else if (y < x && x < z)
		add_oper(oper, RRB);
}

int		ft_sort_b(t_stack **b, int len, t_oper **oper)
{
	int		x;
	int		y;
	int		z;

	x = (*b)->n;
	y = (len >= 2) ? (*b)->next->n : 0;
	z = (len == 3) ? (*b)->next->next->n : 0;
	if (len == 1)
		return (0);
	else if (len == 2 && x < y)
		add_oper(oper, SB);
	else if (stack_len(*b) == 3 && len == 3)
		ft_sort_b_onplace(b, len, oper);
	else if (len == 3)
		ft_sort_desc(b, len, oper);
	return (0);
}
