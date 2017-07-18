/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 20:50:40 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/01 20:50:41 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

t_match	*ft_history_match(t_his *his, char *new, int l)
{
	t_match	*head;
	t_his	*tmp;

	tmp = his;
	head = NULL;
	while (tmp)
	{
		if (tmp->tory)
		{
			if (!ft_strncmp(new, tmp->tory, l))
			{
				if (!ft_add_match(&head, tmp->tory))
				{
					return (NULL);
				}
			}
		}
		tmp = tmp->prev;
	}
	return (head);
}

void	ft_try_to_print(char *find, int num, char **new, int l)
{
	char	*tmp;
	char	*add;

	if (l == num)
		return ;
	if (!(add = ft_strsub(find + l, 0, num - l)))
		return ;
	ft_putstr(add);
	if (!(tmp = ft_freejoin((*new), add, 3)))
		return ;
	(*new) = ft_freedup(tmp, 1);
}

void	ft_history_check(char **new, t_his *his)
{
	t_match	*mat;
	int		l;
	t_match	*tmp;
	int		num;

	if (!(*new))
		return ;
	l = ft_strlen((*new));
	if (!(mat = ft_history_match(his, *new, l)))
		return ;
	tmp = mat;
	if ((num = ft_tab_match_get(mat)))
	{
		ft_try_to_print(mat->find, num, new, l);
	}
	ft_free_match(mat);
}
