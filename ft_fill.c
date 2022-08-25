/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:56:44 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/22 01:00:43 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_fill_list(int argc, char **argv, t_list **lst)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(lst, ft_lstnew(argv[i], argc - 1));
		i++;
	}
}

void	ft_fill_array(int argc, t_list *lst, int *ar)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		ar[i] = ft_atoi(lst->content);
		lst = lst->next;
		i++;
	}
}
