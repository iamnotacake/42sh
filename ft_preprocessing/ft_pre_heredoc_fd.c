/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_heredoc_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:53:57 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/04 17:54:00 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

extern char	*g_heredoc;

int		ft_fd_to_test(void)
{
	int		fd;
	char	*test;

	test = "/tmp/text.txt";
	if ((fd = open(test, O_RDWR | O_CREAT | O_TRUNC, 0640)) < 2)
		return (0);
	return (fd);
}

int		ft_fd_from_test(void)
{
	int		fd;
	char	*test;

	test = "/tmp/text.txt";
	if ((fd = open(test, O_RDONLY)) < 2)
		return (0);
	return (fd);
}

void	ft_add_to_line(char **line, char **cmp)
{
	char	*tmp;

	if (!(*line) && (*cmp))
		(*line) = ft_freedup((*cmp), 1);
	else if (!(*line) && !(*cmp))
		(*line) = ft_strdup("\n");
	else if ((*line) && (*cmp))
	{
		tmp = ft_freejoin((*line), "\n", 1);
		(*line) = ft_freejoin(tmp, (*cmp), 3);
	}
	else if ((*line) && !(*cmp))
		(*line) = ft_freejoin((*line), "\n", 1);
}

char	*ft_read_from_heredoc(char *doc)
{
	char	*line;
	char	*cmp;

	line = NULL;
	g_heredoc = doc;
	while (1)
	{
		ft_terminal_set();
		ft_putstr("heredoc> ");
		ft_get_line(&cmp, &g_history);
		ft_terminal_set();
		write(1, "\n", 1);
		if (cmp)
		{
			if (!ft_strcmp(cmp, doc))
			{
				free(cmp);
				if (!(line = ft_freejoin(line, "\n", 1)))
					line = ft_strdup("");
				return (line);
			}
		}
		ft_add_to_line(&line, &cmp);
	}
	return (NULL);
}

void	ft_pre_heredoc_fd(t_syntax_tree *tree, t_proc **proc)
{
	int		fd;
	char	*line;

	if (!(fd = ft_fd_to_test()))
	{
		ft_free_proc(proc);
		*proc = NULL;
		write(2, "wtf: error", 10);
	}
	if ((line = ft_read_from_heredoc(tree->args[1])))
	{
		write(fd, line, ft_strlen(line));
		free(line);
		close(fd);
		if (!(fd = ft_fd_from_test()))
		{
			ft_free_proc(proc);
			*proc = NULL;
			write(2, "wtf: error", 10);
			ft_putendl(tree->args[1]);
		}
		(*proc)->dup[0] = fd;
	}
}
