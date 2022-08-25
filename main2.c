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
#include "push_swap.h"

int	ft_len_arr(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	**ft_sp(int argc, char **argv)
{
	int		i;
	char	*temp1;
	char	*temp2;
	char	*str;
	char	**argv_s;

	i = 1;
	str = ft_strdup("");
	while (i < argc)
	{
		temp1 = ft_strjoin(argv[i], " ");
		temp2 = ft_strjoin(str, temp1);
		free(str);
		str = temp2;
		free(temp1);
		i++;
	}
	argv_s = ft_split(str, ' ');
	free(str);
	return (argv_s);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*blst;
	int		*ar;
	char	**argv_s;
	int		argc_s;

	argv_s = ft_sp(argc, argv);
	argc_s = ft_len_arr(argv_s) + 1;
	ar = malloc(sizeof(int) * (argc_s - 1));
	ft_check_arg(argc_s, argv_s);
	ft_fill_list(argc_s, argv_s, &lst);
	ft_fill_array(argc_s, lst, ar);
	ft_sort_array(argc_s - 1, ar);
	ft_sort_list(&lst, &blst, ar, argc_s - 1);
}
