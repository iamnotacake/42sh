/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:50:26 by olyuboch          #+#    #+#             */
/*   Updated: 2017/03/29 14:50:27 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

char	**ft_new_env(char **en)
{
	char	**env;
	int		w;
	int		i;

	i = 0;
	w = ft_count_env(en);
	if (!(env = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	while (en[i])
	{
		env[i] = ft_strdup(en[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	ft_terminal_set(void)
{
	struct termios	termios;

	tcgetattr(2, &termios);
	termios.c_lflag = (termios.c_lflag ^ ICANON) ^ ECHO;
	tcsetattr(2, TCSANOW, &termios);
}

void	ft_loop(char **line, t_his **history, char ***env)
{
	while (1)
	{
		ft_terminal_set();
		(*line) = NULL;
		ft_putstr("$> ");
		ft_get_line(line, history);
		ft_terminal_set();
		if ((*line))
		{
			if (ft_strlen((*line)) != 0)
				ft_parse_args(line, env, history);
			free((*line));
		}
		if (!(*line) || ft_strlen((*line)) == 0)
			write(1, "\n", 1);
		(*line) = NULL;
	}
}

void	ft_start(char **en)
{
	char			*line;
	char			**env;
	t_his			*history;

	ft_signals();
	env = ft_new_env(en);
	history = NULL;
	ft_loop(&line, &history, &env);
}
