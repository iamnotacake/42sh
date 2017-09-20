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
	// int		i;

	// i = 0;
	loc = 0;
	// while (tree->tree[i])
	// {
		ft_pre_by_type(tree, bq, &loc);
		// i++;
	// }
}

int		ft_pre_count_args(char **sp, char **argv)
{
	int	s;
	int	a;

	s = 0;
	a = 0;
	while (sp[s])
		s++;
	if (argv)
	{
		while (argv[a])
			a++;
	}
	// if (a == 0)
	// 	return (0);
	return (a + s);
}

void	ft_pre_realloc_args(char **sp, t_proc **proc)
{
	int		c;
	char	**mas;
	int		i;

	if (!(c = ft_pre_count_args(sp, (*proc)->argv)))
		return ;
	if (!(mas = (char **)malloc(sizeof(char *) * (c + 1))))
		return ;
	mas[c] = NULL;
	c = 0;
	i = 0;
	if ((*proc)->argv)
	{
		while ((*proc)->argv[i])
		{
			mas[c] = ft_strdup((*proc)->argv[i]);
			i++;
			c++;
		}
	}
	i = 0;
	while (sp[i])
	{
		mas[c] = ft_strdup(sp[i]);
		i++;
		c++;
	}
	if ((*proc)->argv)
		ft_free_mas((*proc)->argv);
	(*proc)->argv = mas;
}

void	ft_pre_split_args(char *str, t_proc **proc)
{
	int		i;
	char	**sp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
	// printf("%s\n", str);
	if (!(sp = ft_strsplit(str, ' ')))
		return ;
	ft_pre_realloc_args(sp, proc);
	ft_free_mas(sp);
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
	{
		free(str);
		return ;
	}
	printf("str: %s\n", str);
	ft_pre_split_args(str, proc);
	free(str);
}

void	ft_pre_run_bquote(t_syntax_tree *tree, t_proc **proc)
{
	int		old1;
	int		fd[2];
	t_proc	*bq;

	bq = NULL;
	printf("BQUOTE1\n");
	// ft_pre_find_args(tree, &bq);
	// if (!bq)
	// 	return ;
	old1 = dup(1);
	if (pipe(fd) != 0)
		return ;
	// printf("BQUOTE2\n");
	
	// ft_pre_print_proc(bq);
	dup2(fd[1], 1);
	ft_pre_find_args(tree, &bq);
	// if (bq)
	// 	ft_exec(&bq);
	// ft_pre_print_proc(bq);
	if (bq)
		ft_exec(&bq);
	close(fd[1]);
	dup2(old1, 1);
	close(old1);
	ft_free_proc(bq);
	ft_pre_read_from_dup(&fd[0], proc);
	close(fd[0]);
}

void	ft_pre_bquote(t_syntax_tree *tree, t_proc **proc)
{
	int	i;

	i = 0;
	while (tree->tree[i])
	{
		printf("tree\n");
		ft_pre_run_bquote(tree->tree[i], proc);
		i++;
	}
}
