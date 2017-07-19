/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:05:02 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/18 20:05:04 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table_private.h"

t_hash	*ft_hash_table(const char *const envp[])
{
	t_hash	*new;

	new = NULL;
	if (*envp[0])
		write(1, "afaf\n", 5);
	// new = (t_hash *)malloc(sizeof(t_hash));
	return (new);
}
