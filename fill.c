/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:33:22 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 17:02:45 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_list(t_stack **head, int data)
{
	t_stack	*current;
	t_stack	*new;

	current = *head;
	if (current)
	{
		if (current->next == NULL)
		{
			new = (t_stack *)malloc(sizeof(t_stack));
			new->n = data;
			new->next = NULL;
			current->next = new;
			return (1);
		}
		else
			return (push_list(&(current)->next, data));
	}
	(*head) = (t_stack *)malloc(sizeof(t_stack));
	(*head)->n = data;
	(*head)->next = NULL;
	return (1);
}

void	remove_stack(t_stack **head)
{
	if (*head)
	{
		if ((*head)->next)
			remove_stack(&(*head)->next);
		free((*head)->next);
	}
}

void	clear_memory(t_stack **a, t_stack **b)
{
	remove_stack(a);
	remove_stack(b);
}

void	check_duplicates(t_stack **a)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = *a;
	while (ptr->next)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (ptr->n == tmp->n)
			{
				ft_putendl_fd(ERROR, 1);
				remove_stack(a);
				exit(0);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

void	fill_stack(t_stack **a, char **av)
{
	while (*av != NULL)
	{
		push_list(a, ft_atoi(*av));
		av++;
	}
	check_duplicates(a);
}
