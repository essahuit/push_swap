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

void	ft_print(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
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
