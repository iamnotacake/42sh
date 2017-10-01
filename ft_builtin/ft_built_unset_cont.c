/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_unset_cont.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:01:36 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/10/01 14:01:48 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin_private.h"

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
		ft_hash_free_table();
		ft_hash_table(*env);
	}
	return (0);
}
