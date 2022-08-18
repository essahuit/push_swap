/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:44:11 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/18 04:58:42 by kessalih         ###   ########.fr       */
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

int	ft_check_lst_sort(t_list *lst)
{
	while (lst->next)
	{
		if (ft_atoi(lst->content) > ft_atoi(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

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

int	ft_pos(t_list *lst, int el)
{
	int i;

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

void	ft_push_sort(t_list **lst, t_list **blst, int *ar, int argc)
{
	int	chunk;
	int	i;
	int	j;
	int	x;

	x = 7;
	while (ft_lstsize(*lst) % x == 0)
		x--;
	printf("xxxxxx = %d\n",x);
	chunk = ft_lstsize(*lst) / x;
	i = 1;
	j = 0;
	while (i <= x)
	{
		while (j < i * chunk)
		{
			while (ft_pos_array(ft_atoi((*lst)->content), ar, argc) >= i * chunk)
				ft_move(lst, ar[j], 1);
			pb(lst, blst);
			j++;
		}
		i++;
	}
}

void	ft_sort_100(t_list **lst, t_list **blst, int *ar, int argc)
{
	int	*a;
	int	i;

	i = 0;
	a = malloc(sizeof(int) * ft_lstsize(*lst));;
	ft_push_sort(lst, blst, ar, argc);
	ft_fill_array(ft_lstsize(*lst) + 1, *lst, a);
	ft_sort_array(ft_lstsize(*lst), a);
	//printf("esssssa %d\n",ft_lstsize(*lst));
	if (ft_lstsize(*lst) >= 2 && !ft_check_lst_sort(*lst))
		ft_sort_list(lst, blst, a, ft_lstsize(*lst));
	//printf("%d\n",ar[ft_pos_array(ft_atoi((*lst)->content), ar, argc) - 1]);
	while (*blst)
	{
		while (ar[ft_pos_array(ft_atoi((*lst)->content), ar, argc) - 1] != ft_atoi((*blst)->content))
			ft_move(blst, ar[ft_pos_array(ft_atoi((*lst)->content), ar, argc) - 1], 0);
		pa(lst, blst);
	}
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
	else if (argc <= 100)
		ft_sort_100(lst, blst, ar, argc);
	else if (argc <= 500)
		ft_sort_100(lst, blst, ar, argc);
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
	ft_fill_array(argc, lst, ar);
	ft_sort_array(argc - 1, ar);
	//ft_print_lst(lst);
	//while (i < argc - 1)
	//{
	//	printf("%d\n",ar[i]);
	//	i++;
	//}
	//ft_print_lst(lst);
	ft_sort_list(&lst,&blst, ar, argc - 1);
	ft_print_lst(lst);
	//ft_print_lst(blst);
	//while (lst)
	//{
	//	printf("****%d****\n",ft_pos_array(ft_atoi(lst->content), ar, argc - 1));
	//	lst = lst->next;
	//}
	while (1);
}
