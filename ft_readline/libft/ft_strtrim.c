/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:50:34 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 19:14:43 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	int		b;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	b = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b--;
	if (b < 0)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(b - i + 2);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, (s + i), (b - i + 1));
	str[b - i + 1] = '\0';
	return (str);
}
