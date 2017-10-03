/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_change_pwd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:36:32 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 16:36:34 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"

void	ft_change_oldpwd(char ***env, char *oldpwd, int o)
{
	char	*pth;

	if (!(pth = ft_strjoin("OLDPWD=", oldpwd)))
		return ;
	free((*env)[o]);
	(*env)[o] = ft_strdup(pth);
	free(pth);
}

void	ft_change_pwd(char ***env, int p)
{
	char	buf[1024];
	char	*pwd;

	if (!getcwd(buf, sizeof(buf)) || !(*env)[p])
		return ;
	if (!(pwd = ft_strjoin("PWD=", buf)))
		return ;
	free((*env)[p]);
	(*env)[p] = ft_strdup(pwd);
	free(pwd);
}

void	ft_built_change_pwd(char ***env, char *oldpwd, int p, int o)
{
	ft_change_pwd(env, p);
	ft_change_oldpwd(env, oldpwd, o);
}
