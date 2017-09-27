/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:00:21 by olyuboch          #+#    #+#             */
/*   Updated: 2017/06/29 16:00:23 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		ft_find_slash(char *cut)
{
	int	i;
	int	l;

	i = 0;
	if (!cut)
		return (0);
	else
	{
		l = ft_strlen(cut) - 1;
		while (l != -1)
		{
			if (l == -1)
				return (0);
			if (cut[l] == '/')
				return (l + 1);
			l--;
		}
	}
	return (0);
}

char	*ft_tab_ch_folders(char **cut)
{
	int		sl;
	int		l;
	char	*fold;
	char	*new;

	l = ft_strlen(*cut);
	if (!(sl = ft_find_slash(*cut)))
		return (NULL);
	if (!(fold = ft_strsub(*cut, 0, sl)))
		return (NULL);
	if (!(new = ft_strsub(*cut, sl, l - sl)))
		return (NULL);
	free((*cut));
	*cut = new;
	return (fold);
}

void	ft_tab_cut(char **lft, int sp, int l)
{
	char	*cut;
	char	*fold;

	if (!(cut = ft_strsub(*lft, sp, l - sp)))
		return ;
	if (!(fold = ft_tab_ch_folders(&cut)))
	{
		ft_tab_print_match(NULL, cut, lft);
	}
	else
	{
		ft_tab_print_match(fold, cut, lft);
	}
	free(cut);
	if (fold)
		free(fold);
}
