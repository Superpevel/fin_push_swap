#include "push_swap.h"

long long	ft_atoi_ll(const char *str)
{
	long long	sign;
	long long	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10;
		num = num + (*str - '0');
		str++;
	}
	return (sign * num);
}

int			check_input(char **av)
{
	int			i;
	int			j;
	long long	n;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		n = ft_atoi_ll(av[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		while (av[i][j] != '\0')
		{
			if (av[i][j] == '-')
				j++;
			if (!(48 <= av[i][j] && av[i][j] <= 57))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
