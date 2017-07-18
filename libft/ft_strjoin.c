/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:11:54 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/03 20:33:33 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = ft_strnew(l1 + l2 + 1);
	if (!s3)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcpy((s3 + l1), s2);
	s3[l1 + l2] = '\0';
	return (s3);
}
