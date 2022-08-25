/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:41:10 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/25 09:46:28 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sb(t_list **blst)
{
	swap(blst, "sb\n");
}

void	rra(t_list **lst)
{
	reverse_rotate(lst, "rra\n");
}

void	rrb(t_list **blst)
{
	reverse_rotate(blst, "rrb\n");
}
