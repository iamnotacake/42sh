/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:19:11 by alischyn          #+#    #+#             */
/*   Updated: 2017/07/31 16:15:31 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

extern char		**g_env_g;
extern char		**g_env_l;

void			ft_env_init(char ***env, const char *const envp[])
{
	int			i;

	i = 0;
	while (envp[i])
		i++;
	(*env) = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		(*env)[i] = strdup(envp[i]);
		i++;
	}
	(*env)[i] = NULL;
}

int				ft_env_set(char ***env, const char *var, const char *val)
{
	char		*str;
	int			index;

	str = malloc(strlen(var) + strlen(val) + 2);
	strcpy(str, var);
	strcat(str, "=");
	strcat(str, val);
	if ((index = ft_env_util_find(*env, var)) == -1)
	{
		index = ft_env_util_realloc(env);
		(*env)[index] = str;
		(*env)[index + 1] = NULL;
	}
	else
	{
		free((*env)[index]);
		(*env)[index] = str;
	}
	return (1);
}

char			*ft_env_get(char **env, const char *var)
{
	int			index;

	if ((index = ft_env_util_find(env, var)) == -1)
		return (NULL);
	return (env[index] + strlen(var) + 1);
}

int				ft_env_del(char ***env, const char *var)
{
	int			index;
	int			count;

	if ((index = ft_env_util_find(*env, var)) == -1)
		return (0);
	free((*env)[index]);
	count = index;
	while ((*env)[count])
		count++;
	count -= index;
	memmove(env[index], env[index + 1], sizeof(char *) * count);
	return (1);
}
