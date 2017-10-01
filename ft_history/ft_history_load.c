/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:04:33 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:29:00 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

void	ft_exec_write_42history(char *pth, char *str, int fl)
{
	int		fd;

	if ((fd = open(pth, O_WRONLY | O_CREAT | fl, 0640)) < 2)
		return ;
	if (str)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
	close(fd);
}

void	ft_history_load(char *str, int fl)
{
	int		e;
	char	*home;
	char	*pth;

	if (!(e = ft_built_find_path(g_env_g, "HOME")))
		return ;
	home = g_env_g[e];
	while (home && *home != '=')
		home++;
	if (home != NULL)
		home++;
	pth = ft_strjoin(home, "/.42sh_history");
	ft_exec_write_42history(pth, str, fl);
	free(pth);
}
