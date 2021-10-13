#include "push_swap.h"

char	*swap(t_stack *head, int id)
{
	t_stack	*tmp;
	int		swp;

	tmp = head;
	if (tmp && tmp->next)
	{
		swp = tmp->n;
		tmp->n = tmp->next->n;
		tmp->next->n = swp;
		if (id == 1)
			return ("sa");
		else if (id == 2)
			return ("sb");
	}
	return ("");
}

void	sswap(t_stack *a, t_stack *b)
{
	swap(a, 1);
	swap(b, 2);
}
