/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:02:56 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 17:02:58 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push(t_stack **a, t_stack **b, int id)
{
	t_stack	*tmp;

	tmp = *b;
	if (!tmp)
		return ("");
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	if (id == 1)
		return ("pa");
	return ("pb");
}

char	*rotate(t_stack **head, int id)
{
	t_stack	*tmp;
	t_stack	*rot;

	tmp = *head;
	if (tmp && tmp->next)
	{
		(*head) = (*head)->next;
		tmp->next = NULL;
		rot = (*head);
		while (rot->next)
			rot = rot->next;
		rot->next = tmp;
		if (id == 1)
			return ("ra");
		else if (id == 2)
			return ("rb");
	}
	return ("");
}

char	*revrotate(t_stack **head, int id)
{
	t_stack	*seclast;
	t_stack	*last;

	seclast = NULL;
	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ("");
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = *head;
	*head = last;
	if (id == 1)
		return ("rra");
	return ("rrb");
}

void	rrotate(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 0);
}

void	rrevrotate(t_stack **a, t_stack **b)
{
	revrotate(a, 0);
	revrotate(b, 0);
}
