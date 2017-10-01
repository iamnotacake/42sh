/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:32:05 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 16:32:06 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin_private.h"

char	*ft_make_home(char ***env, int h, char **mas, int i)
{
	char	*pth;
	char	*tmp;

	pth = NULL;
	tmp = NULL;
	if (!(tmp = ft_strdup((*env)[h] + 5)))
		return (NULL);
	if (!mas[1])
		return (tmp);
	else
	{
		pth = ft_freejoin(tmp, mas[i] + 1, 1);
		// printf("\n%s\n", pth);
	}
	return (pth);
}

char	*ft_up_pth(char *str)
{
	char	*tmp;
	int		i;
	int		sl;
	char	*pth;

	i = 0;
	if (!(tmp = ft_strdup(str + 4)))
		return (NULL);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '/')
			sl = i;
		i++;
	}
	if (sl == 0)
		*(tmp + 1) = '\0';
	else
		*(tmp + sl) = '\0';
	pth = ft_strdup(tmp);
	free(tmp);
	return (pth);
}

char	*ft_old_pth(char **env, int o, int h)
{
	char	*oldpwd;
	char	*home;
	size_t	ih;

	oldpwd = ft_strdup(env[o] + 7);
	home = ft_strdup(env[h] + 5);
	ih = ft_strlen(home);
	if (ft_strcmp(oldpwd, home) < 0)
		ft_putendl(oldpwd);
	else if (!ft_strcmp(oldpwd, home))
		ft_putendl("~");
	else
	{
		write(1, "~", 1);
		ft_putendl(oldpwd + ih);
	}
	free(home);
	return (oldpwd);
}

char	*ft_cmp_path(char ***env, char **mas, int p, int o)
{
	int		i;
	int		h;
	char	*pth;

	i = 0;
	pth = NULL;
	h = ft_built_find_path(*env, "HOME=");
	while (mas[i])
		i++;
	i--;
	if (!mas[1] || mas[i][0] == '~')
		pth = ft_make_home(env, h, mas, i);
	else if (!ft_strcmp("..", mas[i]))
		pth = ft_up_pth((*env)[p]);
	else if (!ft_strcmp("-", mas[i]))
		pth = ft_old_pth(*env, o, h);
	else
		pth = ft_built_dir_by_path(mas[i]);
	return (pth);
}

int		ft_built_cd(char ***env, char **mas)
{
	char	*pth;
	int		p;
	int		o;
	char	oldpwd[1024];

	getcwd(oldpwd, sizeof(oldpwd));
	p = ft_built_find_path(*env, "PWD");
	o = ft_built_find_path(*env, "OLDPWD");
	pth = ft_cmp_path(env, mas, p, o);
	if (chdir(pth))
	{
		write(1, "cd: no such file or directory: ", 31);
		ft_putendl(mas[1]);
		return (-1);
	}
	else
		ft_built_change_pwd(env, oldpwd, p, o);
	free(pth);
	return (0);
}
