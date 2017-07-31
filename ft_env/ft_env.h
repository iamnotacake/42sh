#ifndef __FT_ENV_H
# define __FT_ENV_H

# include <stdlib.h>
# include <string.h>

char			**g_env_g;
char			**g_env_l;

void			ft_env_init(char ***env, const char *const envp[]);
int				ft_env_set(char ***env, const char *var, const char *val);
char			*ft_env_get(char **env, const char *var);
int				ft_env_del(char ***env, const char *var);

int				ft_env_util_find(const char *const *env, const char *var);
int				ft_env_util_realloc(char ***env);
int				ft_env_util_iter(const char *const *env,
									void (*func)(const char *));

#endif
