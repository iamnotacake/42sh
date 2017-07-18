/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:08:00 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/13 16:01:42 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(long int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*s;
	long int	num;
	size_t		i;

	num = n;
	i = ft_size(n);
	if (!(s = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		num *= -1;
	}
	s[i] = '\0';
	while (num >= 10)
	{
		s[i - 1] = (num % 10) + 48;
		num /= 10;
		i--;
	}
	s[i - 1] = num + 48;
	return (s);
}
