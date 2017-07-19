/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:17:42 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/19 20:17:44 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table_private.h"

char	**ft_get_path(const char *const env[])
{
	int		e;
	int		i;
	char	*tmp;
	char	**pth;
	char	*str;

	str = "PATH";
	e = 0;
	while (env[e])
	{
		i = 0;
		while (env[e][i] == str[i])
		{
			if (env[e][i + 1] == '=')
			{
				tmp = ft_strdup(env[e] + i + 2);
				pth = ft_strsplit(tmp, ':');
				free(tmp);
				return (pth);
			}
			i++;
		}
		e++;
	}
	return (NULL);
}
