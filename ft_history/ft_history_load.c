/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:04:33 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/27 15:04:35 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

void	ft_exec_write_42history(char *tmp)
{
	int	fd;
	t_his	*his;

	if ((fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0640)) < 2)
		return ;
	his = g_history;
	while (his->prev)
		his = his->prev;
	while (his->next && his->next->tory != NULL)
	{
		write(fd, his->tory, ft_strlen(his->tory));
		write(fd, "\n", 1);
		his = his->next;
	}
	close(fd);
}

void	ft_history_load(void)
{
	int	e;
	char	*str;
	char	*tmp;

	if (!g_history)
		return ;
	if (!(e = ft_built_find_path(g_env_g, "HOME")))
		return ;
	str = g_env_g[e];
	while (str && *str != '=')
		str++;
	if (str != NULL)
		str++;
	printf("%s\n", str);
	tmp = ft_strjoin(str, "/.42sh_history");
	ft_exec_write_42history(tmp);
	free(tmp);
}
