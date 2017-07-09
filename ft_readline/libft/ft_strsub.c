/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:07:47 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/02 19:11:23 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	while (s[start + i] != '\0' && len != 0)
	{
		s2[i] = s[start + i];
		i++;
		len--;
	}
	s2[i] = '\0';
	return (s2);
}
