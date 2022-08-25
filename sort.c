/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:55:05 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/22 00:59:04 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_3(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	while (!ft_check_lst_sort(*lst))
	{
		first = *lst;
		second = (*lst)->next;
		last = ft_lstlast(*lst);
		if (ft_atoi(first->content) > ft_atoi(second->content))
			sa(lst);
		else if (ft_atoi(second->content) > ft_atoi(last->content))
			rra(lst);
	}
}

void	ft_sort_4(t_list **lst, t_list **blst, int *ar)
{
	while (ft_atoi((*lst)->content) != ar[0])
		ft_move(lst, ar[0], 1);
	pb(lst, blst);
	ft_sort_3(lst);
	pa(lst, blst);
}

void	ft_sort_5(t_list **lst, t_list **blst, int *ar)
{
	while (ft_atoi((*lst)->content) != ar[0])
		ft_move(lst, ar[0], 1);
	pb(lst, blst);
	while (ft_atoi((*lst)->content) != ar[1])
		ft_move(lst, ar[1], 1);
	pb(lst, blst);
	ft_sort_3(lst);
	pa(lst, blst);
	pa(lst, blst);
}

void	ft_sort_100(t_list **lst, t_list **blst, int *ar, int argc)
{
	int	*a;

	a = malloc(sizeof(int) * ft_lstsize(*lst));
	ft_push_sort(lst, blst, ar, argc);
	ft_fill_array(ft_lstsize(*lst) + 1, *lst, a);
	ft_sort_array(ft_lstsize(*lst), a);
	if (ft_lstsize(*lst) >= 2 && !ft_check_lst_sort(*lst))
		ft_sort_list(lst, blst, a, ft_lstsize(*lst));
	ft_push_a(lst, blst, ar, argc);
	while (ft_atoi((*lst)->content) != ar[0])
		rra(lst);
	free(a);
}

void	ft_sort_list(t_list **lst, t_list **blst, int *ar, int argc)
{
	if (argc == 2)
		sa(lst);
	else if (argc == 3)
		ft_sort_3(lst);
	else if (argc == 4)
		ft_sort_4(lst, blst, ar);
	else if (argc == 5)
		ft_sort_5(lst, blst, ar);
	else
		ft_sort_100(lst, blst, ar, argc);
}
