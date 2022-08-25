/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:54:50 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/22 00:57:44 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_array(int argc, int *ar)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - i - 1)
		{
			if (ar[j] > ar[j + 1])
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

t_list	*ft_lstprev(t_list *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	ft_pos(t_list *lst, int el)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (ft_atoi(lst->content) == el)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

void	ft_move(t_list **lst, int el, int flag)
{
	int	mid;
	int	pos;

	mid = ft_lstsize(*lst) / 2;
	pos = ft_pos(*lst, el);
	if (pos <= mid)
	{
		if (flag == 1)
			ra(lst);
		else
			rb(lst);
	}
	else
	{
		if (flag == 1)
			rra(lst);
		else
			rrb(lst);
	}
}

void	ft_push_a(t_list **lst, t_list **blst, int *ar, int argc)
{
	int		i;
	t_list	*last;
	int		indexlast;
	int		top_blst;

	while (*blst)
	{
		last = ft_lstlast(*lst);
		indexlast = ft_pos_array(ft_atoi(last->content), ar, argc);
		i = ft_pos_array(ft_atoi((*lst)->content), ar, argc);
		if (indexlast == argc - 1)
			indexlast = -1;
		top_blst = ft_pos_array(ft_atoi((*blst)->content), ar, argc);
		if (i - 1 == top_blst)
			pa(lst, blst);
		else if (top_blst > indexlast && top_blst < i)
		{
			pa(lst, blst);
			ra(lst);
		}
		else if (ft_pos(*blst, ar[i - 1]) != -1)
			ft_move(blst, ar[i - 1], 0);
		else if (ft_pos(*blst, ar[i - 1]) == -1)
			rra(lst);
	}
}
