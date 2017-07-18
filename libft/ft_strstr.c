/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:37:40 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 20:16:08 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	b;
	int	l;

	if (!*little)
		return ((char*)big);
	while (*big != '\0')
	{
		l = 0;
		b = 0;
		while (big[b] == little[l] && little[l] != '\0')
		{
			b++;
			l++;
			if (little[l] == '\0')
				return ((char*)big + (b - l));
		}
		big++;
	}
	return (0);
}
