/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:44:11 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/17 05:04:51 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				exit(1);
			j++;
		}
		i++;
	}
}

void	ft_check_sort(int argc, char **argv)
{
	
}

void	ft_check_arg(int argc, char **argv)
{
	if (argc >= 2)
	{
		ft_check_dup(argc, argv);
		ft_check_sort(argc, argv);
	}
	else
		exit(1);
}

void	ft_fill_list(int argc, char **argv, t_list **lst)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(lst, ft_lstnew(argv[i]));
		i++;
	}
}

void	ft_fill_array(int argc, char **argv, int *ar)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ar[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}

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

void	ft_print_lst(t_list *lst)
{
	printf("*******\n");
	while (lst)
	{
		printf("%s\n",lst->content);
		lst = lst->next;
	}
	printf("*******\n");
}

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
		printf("%s\n",str);
	}
}

void	ra(t_list **lst)
{
	rotate(lst, "ra");
}

void	rb(t_list **blst)
{
	rotate(blst, "rb");
}

void	push(t_list **lst1, t_list **lst2, char *str)
{
	t_list	*temp;

	temp = *lst1;
	if (ft_lstsize(*lst1) >= 1)
	{
		(*lst1) = (*lst1)->next;
		ft_lstadd_front(lst2, temp);
		printf("%s\n",str);
	}
}

void	pb(t_list **lst, t_list **blst)
{
	push(lst, blst, "pb");
}

void	pa(t_list **lst, t_list **blst)
{
	push(blst, lst, "pa");
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
		printf("%s\n",str);
	}
}

void	sa(t_list **lst)
{
	swap(lst, "sa");
}

void	sb(t_list **blst)
{
	swap(blst, "sb");
}

t_list	*ft_lstprev(t_list *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
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
		printf("%s\n",str);
	}
}

void	rra(t_list **lst)
{
	reverse_rotate(lst, "rra");
}

void	rrb(t_list **blst)
{
	reverse_rotate(blst, "rrb");
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*blst;
	int		*ar;
	int		i;

	i = 0;
	ar = malloc(sizeof(int) * (argc - 1));
	ft_check_arg(argc, argv);
	ft_fill_list(argc, argv,&lst);
	ft_fill_array(argc, argv, ar);
	ft_sort_array(argc - 1, ar);
}
