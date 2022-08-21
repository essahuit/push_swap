/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:44:11 by kessalih          #+#    #+#             */
/*   Updated: 2022/08/21 05:19:40 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	if (!argv[argc - 1])
	{
		i = 0;
		argc--;
	}
	else
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
	int	i;
	int	j;
	int	k;

	k = 0;
	if (!argv[argc - 1])
	{
		i = 0;
		argc--;
	}
	else
		i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			k = 1;
		i++;
	}
	if (k == 0)
		exit(0);
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

	if (!argv[argc - 1])
	{
		i = 0;
		argc--;
	}
	else
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
		printf("%s\n", str);
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
		printf("%s\n", str);
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
		printf("%s\n", str);
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

int	ft_min_ele(int ele, t_list *lst, int mid, int size)
{
	int	i;
	int	k;

	i = 0;
	while (lst)
	{
		if (ft_atoi(lst->content) == ele)
			break ;
		lst = lst->next;
		i++;
	}
	if (i <= mid)
		k = i;
	else
		k = size - i + 1;
	return (k);
}

int	ft_get_top(int *a, t_list *lst, int *ar, int i, int y)
{
	int	mid;
	int	chunk;
	int	j;
	int	x;
	int	index;

	x = 0;
	chunk = (ft_lstsize(lst) - 4) / y;
	mid = ft_lstsize(lst) / y;
	j = (chunk * (i - 1));
	while (j < i * chunk)
	{
		a[x] = ft_min_ele(ar[j], lst, mid, ft_lstsize(lst));
		j++;
		x++;
	}
	j = 0;
	index = 0;
	while (j < x - 1)
	{
		if (a[j] > a[j + 1])
			index = j + 1;
		j++;
	}
	return (ar[(chunk * (i - 1)) + j]);
}

void	ft_push_sort2(t_list **lst, t_list **blst, int *ar, int argc, int x)
{
	int	i;
	int	j;
	int	chunk;
	int	mid;
	int	*a;

	i = 1;
	j = 0;
	chunk = (ft_lstsize(*lst) - 4) / x;
	while (i <= x)
	{
		mid = (((i - 1) * chunk) + (i * chunk)) / 2;
		a = malloc(sizeof(int) * (i * chunk));
		while (j < i * chunk)
		{
			while (ft_pos_array(ft_atoi((*lst)->content), ar, argc) >= i * chunk)
				ft_move(lst, ft_get_top(a, *lst, ar, i, x), 1);
			pb(lst, blst);
			if (ft_pos_array(ft_atoi((*blst)->content), ar, argc) <= mid)
				rb(blst);
			j++;
		}
		free(a);
		i++;
	}
}

void	ft_push_sort(t_list **lst, t_list **blst, int *ar, int argc)
{
	int	x;

	if (ft_lstsize(*lst) <= 100)
		x = 3;
	else
		x = 5;
	while ((((ft_lstsize(*lst) - 4) % x) + 3 >= 5))
		x--;
	ft_push_sort2(lst, blst, ar, argc, x);
}

void	ft_print(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
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

void	ft_sort_100(t_list **lst, t_list **blst, int *ar, int argc)
{
	int	*a;

	a = malloc(sizeof(int) * ft_lstsize(*lst));
	ft_push_sort(lst, blst, ar, argc);
	ft_fill_array(ft_lstsize(*lst) + 1, *lst, a);
	ft_sort_array(ft_lstsize(*lst), a);
	if (ft_lstsize(*lst) >= 2 && !ft_check_lst_sort(*lst))
		ft_sort_list(lst, blst, a, ft_lstsize(*lst));
	while (!ft_check_lst_sort(*lst))
		rra(lst);
	ft_push_a(lst, blst, ar, argc);
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
	else if (argc <= 100)
		ft_sort_100(lst, blst, ar, argc);
	else
		ft_sort_100(lst, blst, ar, argc);
}

int	ft_len_arr(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*blst;
	int		*ar;
	char	**argv_s;
	int		argc_s;

	if (argc == 2)
	{
		argv_s = ft_split(argv[1], ' ');
		argc_s = ft_len_arr(argv_s) + 1;
	}
	else
	{
		argc_s = argc;
		argv_s = argv;
	}
	ar = malloc(sizeof(int) * (argc_s - 1));
	ft_check_arg(argc_s, argv_s);
	ft_fill_list(argc_s, argv_s, &lst);
	ft_fill_array(argc_s, lst, ar);
	ft_sort_array(argc_s - 1, ar);
	ft_sort_list(&lst, &blst, ar, argc_s - 1);
}
