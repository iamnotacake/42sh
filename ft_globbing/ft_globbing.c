/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globbing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:45:51 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 17:02:53 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_globbing.h"

static int			ft_do_globing(char *tokens, int flag, int cur_char, int c)
{
	char			*pwd;
	struct dirent	*dirbuf;
	DIR				*dfd;

	pwd = ft_env_get(g_env_g, "PWD");
	if ((dfd = opendir(pwd)) == NULL)
		return (0);
	while ((dirbuf = readdir(dfd)) != NULL)
	{
		if (dirbuf->d_ino == 0)
			continue;
		if (ft_strcmp(dirbuf->d_name, ".") == 0 ||\
			ft_strcmp(dirbuf->d_name, "..") == 0 || *(dirbuf->d_name) == '.')
			continue;
		if (ft_match(dirbuf->d_name, tokens, cur_char, c))
		{
			ft_globbing_callback(strdup(dirbuf->d_name));
			flag = 1;
		}
	}
	closedir(dfd);
	return (flag);
}

int					ft_globbing_is_pattern(char *pattern)
{
	static char		globchars[] = "*?[{";
	char			*p;
	int				cur_char;
	int				c;

	cur_char = 0;
	c = 0;
	p = pattern;
	while (*p)
	{
		if (ft_strchr(globchars, *p))
			return (ft_do_globing(pattern, 0, cur_char, c));
		p++;
	}
	return (0);
}
