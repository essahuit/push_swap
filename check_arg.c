/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:53:36 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/22 01:00:31 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_perror(int x)
{
	printf("Error\n");
	exit(x);
}

int	ft_check_lst_sort(t_list *lst)
{
	while (lst->next)
	{
		if (ft_atoi(lst->content) > ft_atoi(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	if (!argv[argc - 1])
	{
		i = 0;
		argc--;
	}
	else
		i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				ft_perror(1);
			j++;
		}
		i++;
	}
}

void	ft_check_sort(int argc, char **argv)
{
	int	i;
	int	k;

	k = 0;
	if (!argv[argc - 1])
	{
		i = 0;
		argc--;
	}
	else
		i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			k = 1;
		i++;
	}
	if (k == 0)
		exit(0);
}

void	ft_check_arg(int argc, char **argv)
{
	if (argc >= 2)
	{
		ft_check_dup(argc, argv);
		ft_check_sort(argc, argv);
	}
	else
		ft_perror(1);
}
