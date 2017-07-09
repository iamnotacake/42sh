#include "ft_readline_private.h"

int		ft_count_env(const char **envp)
{
	int	w;

	w = 0;
	while (envp[w])
		w++;
	return (w);
}

char	**ft_copy_env(const char **envp)
{
	char	**env;
	int		w;
	int		i;

	i = 0;
	w = ft_count_env(envp);
	if (!(env = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}


void	*ft_readline(const char **envp)
{
	char	**env;
	int		i;

	i = 0;
	env = ft_copy_env(envp);
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

