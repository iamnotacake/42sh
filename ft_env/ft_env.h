/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:47:57 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/26 18:48:01 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_ENV_H
# define __FT_ENV_H

# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

extern char		**g_env_g;
extern char		**g_env_l;

char			**ft_env_init(const char *const envp[]);
void			ft_env_set(char ***env, const char *key, const char *value);
char			*ft_env_get(char **env, const char *key);
void			ft_env_remove(char ***env, const char *key);

#endif
