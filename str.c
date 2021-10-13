/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:51:53 by selbert           #+#    #+#             */
/*   Updated: 2021/10/13 14:52:01 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int	ft_str_equal(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	while ((*s1 - *s2) == 0 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if ((*s1 - *s2) != 0)
		return (0);
	return (1);
}
