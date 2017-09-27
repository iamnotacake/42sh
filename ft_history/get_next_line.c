/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 20:36:55 by mvarga            #+#    #+#             */
/*   Updated: 2017/01/27 15:24:34 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

static t_fd			*find_create_fd(const int fd, t_fd **pfile)
{
	t_fd			*pnew;

	pnew = *pfile;
	while (pnew)
	{
		if (pnew->fd == fd)
			return (pnew);
		pnew = pnew->next;
	}
	if (!(pnew = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
	pnew->fd = fd;
	pnew->s_tmp = NULL;
	pnew->next = *pfile;
	*pfile = pnew;
	return (pnew);
}

static int			readline(char **s_tmp, char **line, char *buff)
{
	char			*next_line;
	char			*beg_line;
	char			*tmp;

	if (!*s_tmp)
		*s_tmp = ft_strdup("\0");
	else
	{
		tmp = ft_strjoin(*s_tmp, buff);
		free(*s_tmp);
		*s_tmp = tmp;
		if ((beg_line = ft_strchr(*s_tmp, '\n')))
		{
			*beg_line = '\0';
			*line = ft_strdup(*s_tmp);
			next_line = ft_strdup(beg_line + 1);
			free(*s_tmp);
			*s_tmp = next_line;
			return (TRUE);
		}
	}
	return (FALSE);
}

int					get_next_line(const int fd, char **line)
{
	ssize_t			nbread;
	char			buff[BUFF + 1];
	static t_fd		*f;
	t_fd			*file;

	if ((file = find_create_fd(fd, &f)) && BUFF < 65535 && BUFF != 0)
	{
		(void)ft_memset(buff, 0, BUFF + 1);
		if (readline(&(file->s_tmp), line, buff))
			return (GNL_INSIDE);
		while ((nbread = read(file->fd, buff, BUFF)) > 0)
		{
			if (readline(&(file->s_tmp), line, buff))
				return (GNL_INSIDE);
			(void)ft_memset(buff, 0, BUFF + 1);
		}
		if (*(file->s_tmp))
		{
			*line = ft_strdup(file->s_tmp);
			ft_strdel(&file->s_tmp);
			return (GNL_INSIDE);
		}
		return (nbread == -1 ? GNL_ERR : GNL_END);
	}
	return (GNL_ERR);
}
