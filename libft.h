/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:41:20 by kessalih          #+#    #+#             */
/*   Updated: 2021/11/04 09:15:38 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	int				x;
	struct s_list	*next;
}		t_list;

void	ft_perror(int x);
void	pb(t_list **lst, t_list **blst);
void	rb(t_list **blst);
void	ra(t_list **lst);
void	pa(t_list **lst, t_list **blst);
void	sa(t_list **lst);
void	sb(t_list **blst);
void	rra(t_list **lst);
void	rrb(t_list **blst);
void	reverse_rotate(t_list **lst, char *str);
void	swap(t_list **lst, char *str);
void	push(t_list **lst1, t_list **lst2, char *str);
void	rotate(t_list **lst, char *str);
int		ft_check_lst_sort(t_list *lst);
void	ft_check_arg(int argc, char **argv);
void	ft_sort_list(t_list **lst, t_list **blst, int *ar, int argc);
void	ft_fill_list(int argc, char **argv, t_list **lst);
void	ft_fill_array(int argc, t_list *lst, int *ar);
void	ft_sort_array(int argc, int *ar);
t_list	*ft_lstprev(t_list *lst);
int		ft_pos(t_list *lst, int el);
void	ft_move(t_list **lst, int el, int flag);
void	ft_push_a(t_list **lst, t_list **blst, int *ar, int argc);
int		ft_pos_array(int el, int *ar, int argc);
int		ft_min_ele(int ele, t_list *lst, int mid, int size);
int		ft_get_top(int *a, t_list *lst, int *ar, int i);
void	ft_push_sort(t_list **lst, t_list **blst, int *ar, int argc);
int		ft_x(int argc);
void	ft_sort_list(t_list **lst, t_list **blst, int *ar, int argc);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content, int argc);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
