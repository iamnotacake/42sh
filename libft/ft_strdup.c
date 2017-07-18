/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:08:52 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 20:09:05 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*s;
	int		b;

	a = ft_strlen(s1);
	s = (char *)malloc((a + 1) * sizeof(char));
	if (!s)
		return (NULL);
	b = 0;
	while (s1[b] != '\0')
	{
		s[b] = s1[b];
		b++;
	}
	s[b] = '\0';
	return (s);
}
