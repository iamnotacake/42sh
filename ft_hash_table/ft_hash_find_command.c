/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_find_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:18:28 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/21 11:18:30 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table_private.h"

char	*ft_hash_find_command(char *com)
{
	int		hash;
	t_lst	*tmp;

	if (table == NULL || com == NULL)
		return (NULL);
	hash = ft_hash_function(com);
	// ft_putnbr(hash);
	if (table[hash].lst)
	{
		tmp = table[hash].lst;
		while (tmp)
		{
			if (!ft_strcmp(com, tmp->com))
				return (ft_strdup(tmp->pth));
			tmp = tmp->next;
		}
	}
	return (NULL);
}