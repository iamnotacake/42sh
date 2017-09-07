/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:26:01 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 16:26:03 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin_private.h"

int		ft_if_true(char *env, char *mas)
{
	int	i;

	i = 0;
	while (mas[i] == env[i])
	{
		if (env[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_del_env(char ***env, char **mas, char **new)
{
	int		e;
	int		m;
	int		n;
	int		coinc;

	n = 0;
	e = 0;
	while ((*env)[e])
	{
		coinc = 0;
		m = 0;
		while (mas[++m])
			coinc += ft_if_true((*env)[e], mas[m]);
		if (coinc == 0)
		{
			new[n] = ft_strdup((*env)[e]);
			n++;
		}
		free((*env)[e]);
		e++;
	}
	free((*env));
	new[n] = NULL;
	*env = new;
}

int		ft_cmp(char **env, char *str)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while (env[w])
	{
		while (str[i] == env[w][i])
		{
			if (env[w][i + 1] == '=')
				return (1);
			i++;
		}
		w++;
	}
	return (0);
}

int		ft_ch_mas(char **env, char **mas)
{
	int	w;
	int	c;

	w = 0;
	c = 0;
	while (mas[w])
	{
		c += ft_cmp(env, mas[w]);
		w++;
	}
	return (c);
}

int		ft_built_unsetenv(char ***env, char **mas)
{
	int		m;
	int		word;
	char	**new;

	if ((m = ft_ch_mas(*env, mas)))
	{
		word = ft_count_env((*env)) - m;
		if (!(new = (char **)malloc(sizeof(char *) * (word + 1))))
			return (-1);
		ft_del_env(env, mas, new);
	}
	return (0);
}
