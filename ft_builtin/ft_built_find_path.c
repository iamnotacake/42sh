/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_find_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:34:33 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 16:34:35 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"

int		ft_built_find_path(char **env, char *str)
{
	int		e;
	int		i;

	e = 0;
	while (env[e])
	{
		i = 0;
		while (env[e][i] == str[i] || (env[e][i + 1] == '=' && !str[i + 1]))
		{
			if (env[e][i + 1] == '=' &&
				(!str[i + 1] || str[i + 1] == '=' || str[i + 1] == ' '))
				return (e);
			i++;
		}
		e++;
	}
	return (0);
}
