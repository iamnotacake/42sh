/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 12:09:22 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/15 12:09:24 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

void	ft_pre_permission_error(t_syntax_tree *tree, t_proc **proc)
{
	ft_free_proc(*proc);
	*proc = NULL;
	write(2, "wtf: permission denied: ", 24);
	ft_putendl(tree->args[1]);
}

void	ft_pre_write_fd(t_syntax_tree *tree, t_proc **proc)
{
	int	fd;

	if (tree->args[0][1] == '1')
	{
		if ((fd = open(tree->args[1], O_WRONLY |
			O_CREAT | O_TRUNC, 0640)) < 2)
			ft_pre_permission_error(tree, proc);
		else
			(*proc)->dup[1] = fd;
	}
}

void	ft_pre_append_fd(t_syntax_tree *tree, t_proc **proc)
{
	int	fd;

	if (tree->args[0][1] == '1')
	{
		if ((fd = open(tree->args[1], O_WRONLY |
			O_CREAT | O_APPEND, 0640)) < 2)
			ft_pre_permission_error(tree, proc);
		else
			(*proc)->dup[1] = fd;
	}
}

void	ft_pre_read_fd(t_syntax_tree *tree, t_proc **proc)
{
	int	fd;

	if (tree->args[0][1] == '0')
	{
		if ((fd = open(tree->args[1], O_WRONLY |
			O_CREAT | O_APPEND, 0640)) < 2)
			ft_pre_permission_error(tree, proc);
		else
			(*proc)->dup[0] = fd;
	}
}

void	ft_pre_redirection(t_syntax_tree *tree, t_proc **proc)
{
	if (tree->args[0][0] == 'w')
		ft_pre_write_fd(tree, proc);
	else if (tree->args[0][0] == 'a')
		ft_pre_append_fd(tree, proc);
	else if (tree->args[0][0] == 'r')
		ft_pre_read_fd(tree, proc);
	else if (tree->args[0][0] == 'h')
		ft_pre_heredoc_fd(tree, proc);
}
