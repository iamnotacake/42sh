/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:40:38 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 20:22:34 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		b;
	int		l;
	size_t	s;

	if (!*little)
		return ((char*)big);
	while (*big != '\0' && len != 0)
	{
		l = 0;
		b = 0;
		s = len;
		while (big[b] == little[l] && little[l] != '\0' && s != 0)
		{
			b++;
			l++;
			s--;
			if (little[l] == '\0')
				return ((char*)big + (b - l));
		}
		big++;
		len--;
	}
	return (0);
}
