/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:08:56 by alischyn          #+#    #+#             */
/*   Updated: 2017/07/31 16:23:54 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

int				ft_env_util_find(const char *const *env, const char *var)
{
	int			i;
	int			len;

	i = 0;
	len = strlen(var);
	while (env[i])
	{
		if (strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int				ft_env_util_realloc(char ***env)
{
	int			i;

	i = 0;
	while ((*env)[i])
		i++;
	*env = realloc(*env, sizeof(char *) * (i + 2));
	return (i);
}

int				ft_env_util_iter(const char *const *env,
									void (*func)(const char *))
{
	int			i;

	i = 0;
	while (env[i])
		func(env[i++]);
	return (i);
}
