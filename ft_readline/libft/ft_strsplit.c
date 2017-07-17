/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:15:58 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/07 19:52:30 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char *s, char c)
{
	int	sc;

	sc = 0;
	while (*s != '\0')
	{
		if (*s != c && *s != '\0')
		{
			sc++;
			while (*s != c && *s != '\0')
				s++;
		}
		if (*s == c)
			s++;
	}
	return (sc);
}

static char	**ft_mas(char *s, char c)
{
	char	**mas;
	size_t	i;
	int		w;

	i = 0;
	w = ft_words(s, c);
	if (!(mas = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	mas[w] = NULL;
	return (mas);
}

static char	**ft_sam(char *s, char c)
{
	char	**mas;
	size_t	i;
	int		w;

	i = 0;
	if (!(mas = ft_mas(s, c)))
		return (NULL);
	w = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		while (*s != c && *s != '\0')
		{
			i++;
			s++;
			if (*s == c || *s == '\0')
			{
				mas[w] = ft_strsub((s - i), 0, i);
				i = 0;
				w++;
			}
		}
	}
	return (mas);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**masiv;
	char	*s2;

	if (!s || !c)
		return (NULL);
	s2 = (char *)s;
	if (!(masiv = ft_sam(s2, c)))
		return (NULL);
	return (masiv);
}
