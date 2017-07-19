/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:46:37 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/19 20:46:38 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table_private.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char	*ft_concat(char *first, ...)
{
	char		*str;
	size_t		str_len;
	char		*tmp;
	char		*tmp_old;
	va_list		ap;

	va_start(ap, first);
	str = strdup(first);
	tmp_old = first;
	str_len = strlen(str);
	while ((tmp = va_arg(ap, char *)))
	{
		if (tmp == (char *)1)
			free(tmp_old);
		else
		{
			str = realloc(str, str_len + strlen(tmp) + 1);
			strcpy(str + str_len, tmp);
			str_len = strlen(str);
			tmp_old = tmp;
		}
	}
	va_end(ap);
	return (str);
}

void	ft_readdir(char *pth, t_lst *lst)
{
	DIR				*d;
	struct dirent	*dir;
	char			tmp[1000];

	if (!(d = opendir(pth)))
		return ;
	while ((dir = readdir(d)))
	{
		strcpy(tmp, pth);
		strcat(tmp, "/");
		strcat(tmp, dir->d_name);
		// tmp = ft_concat(pth, "/", dir->d_name);
		if (access(tmp, X_OK) == 0 && (dir->d_type == 8 || dir->d_type == 10))
			ft_putendl(dir->d_name);
		// free(tmp);
	}
	closedir(d);
}

t_lst	*ft_create_lst(char **pth)
{
	t_lst	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while (pth[i])
	{
		ft_readdir(pth[i], &lst);
		i++;
	}
	return (NULL);
}
