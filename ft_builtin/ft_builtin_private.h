/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:41:22 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 15:41:24 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_BUILTIN_PRIVATE_H
# define __FT_BUILTIN_PRIVATE_H

# include "ft_env.h"
# include "../libft/libft.h"
# include "ft_readline.h"
# include "ft_hash_table.h"
# include "ft_free.h"

extern t_list	*g_jobs;

int		ft_built_setenv(char ***env, char **mas);
int		ft_built_unsetenv(char ***env, char **mas);
int		ft_built_cd(char ***env, char **mas);
int		ft_built_find_path(char **env, char *str);
void	ft_built_change_pwd(char ***env, char *oldpwd, int p, int o);
char	*ft_built_dir_by_path(char *mas);
int		ft_build_jobs(char **env, char **argv);

#endif
