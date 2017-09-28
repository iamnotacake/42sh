/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_upload.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:45:37 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/27 14:45:38 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

void	ft_history_read(char *tmp)
{
	int		fd;
	t_his	*his;
	char	*line;

	his = NULL;
	line = NULL;
	if ((fd = open(tmp, O_RDONLY)) < 2)
		return ;
	while (get_next_line(fd, &line))
	{
		ft_add_to_history(&g_history, line);
		free(line);
		line = NULL;
	}
	free(line);
	close(fd);
	return ;
}

void	ft_history_upload(void)
{
	int		e;
	char	*str;
	char	*tmp;
	
	if (!g_env_g)
		return ;
	if (!(e = ft_built_find_path(g_env_g, "HOME")))
		return ;
	str = g_env_g[e];
	while (str && *str != '=')
		str++;
	if (str != NULL)
		str++;
	// printf("%s\n", str);
	tmp = ft_strjoin(str, "/.42sh_history");
	ft_history_read(tmp);
	free(tmp);
}
