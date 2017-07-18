/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:05:36 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 19:57:45 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			count;

	ptr = (unsigned char*)b;
	count = 0;
	while (count < len)
	{
		ptr[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
