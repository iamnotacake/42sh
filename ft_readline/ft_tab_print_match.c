/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_print_match.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 20:16:55 by olyuboch          #+#    #+#             */
/*   Updated: 2017/06/29 20:16:57 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

DIR		*ft_tab_opendir(char *fold)
{
	DIR		*d;

	if (fold)
	{
		if (!(d = opendir(fold)))
			return (0);
	}
	else
	{
		if (!(d = opendir("./")))
			return (0);
	}
	return (d);
}

/*
**	void	ft_print_match(t_match *head)
**	{
**		t_match	*tmp;
**
**		tmp = head;
**		while (tmp)
**		{
**			ft_putstr("\n");
**			ft_putstr(tmp->find);
**			tmp = tmp->next;
**		}
**	}
*/

t_focu	*ft_create_focu(char *fold, char *cut)
{
	t_focu	*new;

	if (!(new = (t_focu *)malloc(sizeof(t_focu))))
		return (NULL);
	new->fold = fold;
	new->cut = cut;
	return (new);
}

/*
**	ft_print_match(mat);
*/

void	ft_tab_print_match(char *fold, char *cut, char **lft)
{
	DIR		*d;
	t_match	*mat;
	int		num;
	t_focu	*fo;

	num = 0;
	if (!(d = ft_tab_opendir(fold)))
		return ;
	if (!(mat = ft_tab_find_file(cut, d)))
		return ;
	num = ft_tab_match_get(mat);
	if (!(fo = ft_create_focu(fold, cut)))
		return ;
	ft_tab_try_to_paste(fo, mat->find, num, lft);
	free(fo);
	ft_free_match(mat);
}
