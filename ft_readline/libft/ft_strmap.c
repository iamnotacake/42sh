/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:00:09 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/02 15:44:28 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	if (s == NULL || *f == NULL)
		return (NULL);
	s2 = ft_strdup(s);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = f(s[i]);
		i++;
	}
	return (s2);
}
