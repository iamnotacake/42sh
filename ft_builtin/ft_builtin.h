/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:41:05 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 15:41:07 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_BUILTIN_H
# define __FT_BUILTIN_H

# include "ft_env.h"
# include "../libft/libft.h"
# include "ft_readline.h"
# include "ft_hash_table.h"
# include "ft_free.h"

extern	t_hash	**g_table;

int		ft_built_setenv(char ***env, char **mas);
int		ft_built_unsetenv(char ***env, char **mas);
int		ft_built_cd(char ***env, char **mas);
int		ft_built_find_path(char **env, char *str);
void	ft_built_change_pwd(char ***env, char *oldpwd, int p, int o);
char	*ft_built_dir_by_path(char *mas);
int		ft_ch_mas(char **env, char **mas);
void	ft_del_env(char ***env, char **mas, char **new);

#endif
