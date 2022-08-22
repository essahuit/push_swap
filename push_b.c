/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:54:57 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/22 00:58:40 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_pos_array(int el, int *ar, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (el == ar[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_min_ele(int ele, t_list *lst, int mid, int size)
{
	int	i;
	int	k;

	i = 0;
	while (lst)
	{
		if (ft_atoi(lst->content) == ele)
			break ;
		lst = lst->next;
		i++;
	}
	if (i <= mid)
		k = i;
	else
		k = size - i + 1;
	return (k);
}

int	ft_get_top(int *a, t_list *lst, int *ar, int i)
{
	int	mid;
	int	chunk;
	int	j;
	int	x;
	int	index;

	x = 0;
	chunk = (ft_lstsize(lst) - 4) / lst->x;
	mid = ft_lstsize(lst) / 2;
	j = (chunk * (i - 1));
	while (j < i * chunk)
	{
		a[x] = ft_min_ele(ar[j], lst, mid, ft_lstsize(lst));
		j++;
		x++;
	}
	j = 0;
	index = 0;
	while (j < x - 1)
	{
		if (a[j] > a[j + 1])
			index = j + 1;
		j++;
	}
	return (ar[(chunk * (i - 1)) + j]);
}

int	ft_x(int argc)
{
	int	x;

	if (argc <= 100)
		x = 3;
	else
		x = 5;
	while ((((argc - 4) % x) + 4 >= 5))
		x--;
	return (x);
}

void	ft_push_sort(t_list **lst, t_list **blst, int *ar, int argc)
{
	int	i;
	int	j;
	int	chunk;
	int	mid;
	int	*a;

	i = 1;
	j = 0;
	chunk = (ft_lstsize(*lst) - 4) / (*lst)->x;
	while (i <= (*lst)->x)
	{
		mid = (((i - 1) * chunk) + (i * chunk)) / 2;
		a = malloc(sizeof(int) * (i * chunk));
		while (j < i * chunk)
		{
			while (ft_pos_array(ft_atoi((*lst)->content), ar, argc) >= i * chunk)
				ft_move(lst, ft_get_top(a, *lst, ar, i), 1);
			pb(lst, blst);
			if (ft_pos_array(ft_atoi((*blst)->content), ar, argc) <= mid)
				rb(blst);
			j++;
		}
		free(a);
		i++;
	}
}
