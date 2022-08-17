/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:22:29 by kessalih          #+#    #+#             */
/*   Updated: 2021/11/11 18:22:10 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_check(const char *str, long long n, int sign)
{
	int	i;

	i = 0;

	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit(1);
		i++;
	}
	if (sign == 1)
	{
		if (n > INT_MAX)
			exit(1);
	}
	else
	{
		if (n - 1 > INT_MAX)
			exit(1);
	}
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	long long			n;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
		if (str[i] == '\0')
			exit(1);
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	ft_check(str + i, n, sign);
	n = n * sign;
	return ((int)n);
}
