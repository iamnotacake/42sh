/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 14:59:56 by olyuboch          #+#    #+#             */
/*   Updated: 2017/04/29 14:59:58 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freedup(char *str, int f)
{
	int		l;
	char	*cpy;
	int		i;

	l = ft_strlen(str);
	if (!(cpy = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	if (f != 0)
		free(str);
	return (cpy);
}
