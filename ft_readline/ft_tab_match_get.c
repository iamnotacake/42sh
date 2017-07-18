/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_match_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 19:32:33 by olyuboch          #+#    #+#             */
/*   Updated: 2017/06/29 19:32:35 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

int	ft_count_matches(char *m1, char *m2)
{
	int	i;

	i = 0;
	while (m1[i] && m2[i])
	{
		if (m1[i] != m2[i])
			return (i);
		i++;
	}
	return (i);
}

int	ft_count_num(t_match *mat)
{
	int	num;

	num = -1;
	while (mat)
	{
		if (mat->next)
		{
			if (num == -1)
			{
				if (!(num = ft_count_matches(mat->find, mat->next->find)))
					return (0);
			}
			else
			{
				if (ft_strncmp(mat->find, mat->next->find, num))
					if (!(num = ft_count_matches(mat->find, mat->next->find)))
						return (0);
			}
		}
		mat = mat->next;
	}
	return (num);
}

int	ft_tab_match_get(t_match *mat)
{
	t_match	*tmp;
	int		num;

	tmp = mat;
	num = -1;
	if (!mat->next)
		return (ft_strlen(mat->find));
	num = ft_count_num(mat);
	return (num);
}
