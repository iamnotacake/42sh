/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:54:02 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 20:13:36 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	int		i;

	i = 0;
	lend = ft_strlen(dst);
	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	while ((lend + i) < (size - 1) && src[i] != '\0')
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + ft_strlen(src));
}
