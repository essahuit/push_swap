/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:53:06 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/22 01:00:10 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	rotate(t_list **lst, char *str)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*lst) >= 2)
	{
		temp = (*lst)->next;
		last = ft_lstlast(*lst);
		(*lst)->next = NULL;
		last->next = (*lst);
		*lst = temp;
		printf("%s\n", str);
	}
}

void	push(t_list **lst1, t_list **lst2, char *str)
{
	t_list	*temp;

	temp = *lst1;
	if (ft_lstsize(*lst1) >= 1)
	{
		(*lst1) = (*lst1)->next;
		ft_lstadd_front(lst2, temp);
		printf("%s\n", str);
	}
}

void	swap(t_list **lst, char *str)
{
	t_list	*temp;

	if (ft_lstsize(*lst) >= 2)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		temp->next = (*lst)->next;
		(*lst)->next = temp;
		printf("%s\n", str);
	}
}

void	reverse_rotate(t_list **lst, char *str)
{
	t_list	*temp;
	t_list	*last;
	t_list	*prev;

	if (ft_lstsize(*lst) >= 2)
	{
		temp = (*lst);
		last = ft_lstlast(*lst);
		prev = ft_lstprev(*lst);
		last->next = temp;
		(*lst) = last;
		prev->next = NULL;
		printf("%s\n", str);
	}
}
