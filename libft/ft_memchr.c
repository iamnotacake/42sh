/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:06:16 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 20:03:25 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*b;

	b = (unsigned char*)s;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*b == (unsigned char)c)
				return ((void*)(b));
			b++;
			n--;
		}
	}
	return (NULL);
}
