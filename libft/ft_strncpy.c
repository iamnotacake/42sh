/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:11:48 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 20:10:28 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		a;
	int		st;
	size_t	num;

	a = 0;
	st = (int)ft_strlen(src);
	num = 1;
	while (num <= len)
	{
		if (st >= 0)
			dst[a] = src[a];
		else
			dst[a] = '\0';
		a++;
		num++;
		st--;
	}
	return ((char *)dst);
}
