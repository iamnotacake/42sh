/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:49:43 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 20:14:36 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*str = s;

	if (c == '\0')
	{
		while (*str != '\0')
			str++;
		return ((char*)str);
	}
	else
	{
		while (*s != c && *s != '\0')
			s++;
		if (*s != c)
			return (0);
		return ((char*)s);
	}
}
