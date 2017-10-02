/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_bquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 18:31:43 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/15 18:31:45 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"
#define BUF 1024

void	ft_pre_find_args(t_syntax_tree *tree, t_proc **bq)
{
	int		loc;

	loc = 0;
	ft_pre_by_type(tree, bq, &loc);
}

void	ft_pre_read_from_dup(int *fd, t_proc **proc)
{
	char	*buf;
	char	*str;
	char	*tmp;

	str = NULL;
	if (!(buf = ft_strnew(BUF)))
		return ;
	while (read(fd[0], buf, BUF))
	{
		if (!str)
			str = ft_strdup(buf);
		else
		{
			tmp = ft_freedup(str, 1);
			str = ft_freejoin(tmp, buf, 1);
		}
	}
	free(buf);
	if (!str)
		return ;
	ft_pre_split_args(str, proc);
	free(str);
}

void	ft_pre_run_bquote(t_syntax_tree *tree, t_proc **proc)
{
	int		old1;
	int		fd[2];
	t_proc	*bq;

	bq = NULL;
	old1 = dup(1);
	if (pipe(fd) != 0)
		return ;
	dup2(fd[1], 1);
	ft_pre_find_args(tree, &bq);
	// if (bq)
	// 	ft_exec(&bq);
	close(fd[1]);
	dup2(old1, 1);
	close(old1);
	// ft_free_proc(&bq);
	ft_pre_read_from_dup(&fd[0], proc);
	close(fd[0]);
}

void	ft_pre_bquote(t_syntax_tree *tree, t_proc **proc)
{
	int	i;

	i = 0;
	while (tree->tree[i])
	{
		ft_pre_run_bquote(tree->tree[i], proc);
		i++;
	}
}
