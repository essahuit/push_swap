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
#include "libft.h"

void	ft_fill_list(int argc, char **argv, t_list **lst)
{
	int	i;

	if (!argv[argc - 1])
	{
		i = 0;
		argc--;
	}
	else
		i = 1;
	while (i < argc)
	{
		ft_lstadd_back(lst, ft_lstnew(argv[i], argc - 1));
		i++;
	}
}

void	ft_fill_array(int argc, t_list *lst, int *ar)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ar[i - 1] = ft_atoi(lst->content);
		lst = lst->next;
		i++;
	}
}
