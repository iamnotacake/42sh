/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:30:21 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/20 19:30:23 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"

int	ft_hash_function(char *command)
{
	unsigned int	hash;
	int				i;

	hash = 0;
	i = 0;
	while (command[i])
	{
		hash = (hash << 5) + (hash >> sizeof(hash)) + command[i];
		i++;
	}
	return (hash % HASH_SIZE);
}

// unsigned    ft_hashs(const char *str, unsigned table_size)
// {
//     unsigned    res;

//     res = 0;
//     while (*str)
//     {
//         res = ((res << 2) ^ *str) + ((res >> 22) ^ (*str << 13));
//         str++;
//     }
//     return (res % table_size);
// }
