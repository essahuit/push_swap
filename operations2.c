/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:53:16 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/25 09:46:41 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_list **lst)
{
	rotate(lst, "ra\n");
}

void	rb(t_list **blst)
{
	rotate(blst, "rb\n");
}

void	pb(t_list **lst, t_list **blst)
{
	push(lst, blst, "pb\n");
}

void	pa(t_list **lst, t_list **blst)
{
	push(blst, lst, "pa\n");
}

void	sa(t_list **lst)
{
	swap(lst, "sa\n");
}
