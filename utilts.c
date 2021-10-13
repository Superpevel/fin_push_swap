#include "push_swap.h"

int		stack_len(t_stack *a)
{
	t_stack	*ptr;
	int		len;

	len = 0;
	ptr = a;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		len++;
	}
	return (len);
}

void	optim_operations(t_oper **oper)
{
	int		flag;
	int		all;

	all = 1;
	flag = 0;
	while (all && (*oper))
	{
		all = 0;
		optim_sasa(oper, &flag, &all);
		optim_sbsb(oper, &flag, &all);
		optim_rrara(oper, &flag, &all);
		optim_rrbrb(oper, &flag, &all);

	}
}

void	bubble_sort(int *x, int size)
{
	int		i;
	int		j;
	int		swap;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (x[i] < x[j])
			{
				swap = x[i];
				x[i] = x[j];
				x[j] = swap;
			}
			j++;
		}
		i++;
	}
}

int		ft_pivot(t_stack *a, int len)
{
	int		size;
	int		*x;
	int		i;
	t_stack	*ptr;

	ptr = a;
	size = len;
	i = 0;
	x = (int*)malloc(sizeof(int) * len);
	while (ptr && len--)
	{
		x[i++] = ptr->n;
		ptr = ptr->next;
	}
	i = 0;
	bubble_sort(x, size);
	i = x[size / 2];
	free(x);
	return (i);
}
