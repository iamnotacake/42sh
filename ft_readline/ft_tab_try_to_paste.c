/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_try_to_paste.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 20:35:28 by olyuboch          #+#    #+#             */
/*   Updated: 2017/06/29 20:35:30 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char	*ft_new_add(char *find, int c, int num, char *fold)
{
	char	*tmp;
	char	*add;
	char	*tfol;
	DIR		*d;

	if (!(tmp = ft_strsub(find, 0, num)))
		return (NULL);
	if (!(add = ft_strsub(find, c, num - c)))
		return (NULL);
	if (fold)
		tfol = ft_freejoin(fold, tmp, 2);
	else
		tfol = tmp;
	if ((d = opendir(tfol)))
	{
		free(tfol);
		tfol = NULL;
		closedir(d);
		add = ft_freejoin(add, "/", 1);
	}
	if (tfol)
		free(tfol);
	return (add);
}

/*
** if (!(add = ft_strsub(find, c, num - c)))
** 		return (0);
*/

void	ft_tab_try_to_paste(t_focu *fo, char *find, int num, char **lft)
{
	char	*add;
	int		c;
	char	*tmp;

	c = ft_strlen(fo->cut);
	if (c == num)
		return ;
	if (!(add = ft_new_add(find, c, num, fo->fold)))
		return ;
	ft_putstr(add);
	tmp = ft_freejoin((*lft), add, 3);
	*lft = tmp;
}
