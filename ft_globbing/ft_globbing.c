/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globbing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:45:51 by mvarga            #+#    #+#             */
/*   Updated: 2017/10/02 19:23:25 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_globbing.h"

char g_str[256];

static char			*ft_check_patch(char *pattern, char *s, char *str, int cnt)
{
	while (cnt)
	{
		if (*--s == '/')
		{
			if (cnt == 1)
				*str++ = *pattern++;
			else
			{
				while (pattern != s)
					*str++ = *pattern++;
				*str++ = *pattern++;
			}
			*str = '\0';
			break ;
		}
		cnt--;
	}
	return (pattern);
}

static char			*ft_patch(char *pattern, char p, int cnt)
{
	char		*str;
	char		*s;

	str = g_str;
	s = pattern;
	while (cnt++ < 256)
		*str++ = '\0';
	cnt = 0;
	str = g_str;
	while (*s != p)
	{
		cnt++;
		s++;
	}
	pattern = ft_check_patch(pattern, s, str, cnt);
	return (pattern);
}

static int			ft_do_globing(char *tokens, int flag, int cur_char, int c)
{
	char			*pwd;
	struct dirent	*dirbuf;
	DIR				*dfd;

	if ((ft_strlen(g_str) < 3) && (ft_strlen(g_str) != 1))
		pwd = ft_env_get(g_env_g, "PWD");
	else
		pwd = g_str;
	if ((dfd = opendir(pwd)) == NULL)
		return (0);
	while ((dirbuf = readdir(dfd)) != NULL)
	{
		if (dirbuf->d_ino == 0)
			continue ;
		if (ft_strcmp(dirbuf->d_name, ".") == 0 ||\
			ft_strcmp(dirbuf->d_name, "..") == 0 || *(dirbuf->d_name) == '.')
			continue ;
		if (ft_match(dirbuf->d_name, tokens, cur_char, c))
		{
			ft_globbing_callback(ft_strjoin(g_str, dirbuf->d_name));
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
		{
			pattern = ft_patch(pattern, *p, 0);
			return (ft_do_globing(pattern, 0, cur_char, c));
		}
		p++;
	}
	return (0);
}
