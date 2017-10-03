/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_dir_by_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:38:17 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 16:38:19 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"

char	*ft_root_dir(char *mas)
{
	struct stat	buf;
	char		*pth;

	if (lstat(mas, &buf))
		return (NULL);
	else
		pth = ft_strdup(mas);
	return (pth);
}

char	*ft_path_dir(char *mas)
{
	struct stat	st;
	char		*pth;
	char		buf[1024];
	char		*tmp;

	if (lstat(mas, &st))
		return (NULL);
	else
	{
		getcwd(buf, sizeof(buf));
		tmp = ft_strjoin(buf, "/");
		pth = ft_strjoin(tmp, mas);
		free(tmp);
	}
	return (pth);
}

char	*ft_built_dir_by_path(char *mas)
{
	char	*pth;

	pth = NULL;
	if (mas[0] == '/')
		pth = ft_root_dir(mas);
	else
		pth = ft_path_dir(mas);
	return (pth);
}
