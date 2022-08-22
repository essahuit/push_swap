/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:53:16 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/22 00:59:47 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ra(t_list **lst)
{
	rotate(lst, "ra");
}

void	rb(t_list **blst)
{
	rotate(blst, "rb");
}

void	pb(t_list **lst, t_list **blst)
{
	push(lst, blst, "pb");
}

void	pa(t_list **lst, t_list **blst)
{
	push(blst, lst, "pa");
}

void	sa(t_list **lst)
{
	swap(lst, "sa");
}

void	sb(t_list **blst)
{
	swap(blst, "sb");
}

void	rra(t_list **lst)
{
	reverse_rotate(lst, "rra");
}

void	rrb(t_list **blst)
{
	reverse_rotate(blst, "rrb");
}
