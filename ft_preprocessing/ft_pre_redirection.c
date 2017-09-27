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

void	ft_pre_redir_fd(t_syntax_tree *tree, t_proc **proc, int num2, int def)
{
	int	num1;

	num1 = 0;
	if (!ft_strcmp(tree->args[1], "-"))
	{
		if ((num1 = open("/dev/null", O_WRONLY |
			O_CREAT | def, 0640)) < 2)
		{
			ft_pre_permission_error(tree, proc);
			return ;
		}
	}
	else if (tree->args[1][0] == '&')
	{
		num1 = ft_atoi(tree->args[1] + 1);
	}
	if ((*proc)->dup[num2] != num2 && (*proc)->dup[num2] > 2)
		close((*proc)->dup[num2]);
	(*proc)->dup[num2] = num1;
}

void	ft_pre_write_fd(t_syntax_tree *tree, t_proc **proc, char w)
{
	int	fd;
	int	num2;
	int	def;

	if (w == 'w')
		def = O_TRUNC;
	if (w == 'a')
		def = O_APPEND;
	num2 = ft_atoi(tree->args[0] + 1);
	if (!ft_strcmp(tree->args[1], "-") || tree->args[1][0] == '&')
		ft_pre_redir_fd(tree, proc, num2, def);
	else
	{
		if ((fd = open(tree->args[1], O_WRONLY |
			O_CREAT | def, 0640)) < 2)
			ft_pre_permission_error(tree, proc);
		else
		{
			if ((*proc)->dup[num2] != num2 && (*proc)->dup[num2] > 2)
				close((*proc)->dup[1]);
			(*proc)->dup[num2] = fd;
		}
	}
}

void	ft_pre_read_fd(t_syntax_tree *tree, t_proc **proc)
{
	int	fd;

	if (tree->args[0][1] == '0')
	{
		if ((fd = open(tree->args[1], O_RDONLY)) < 2)
			ft_pre_permission_error(tree, proc);
		else
		{
			if ((*proc)->dup[0] != 0 && (*proc)->dup[0] > 2)
				close((*proc)->dup[0]);
			(*proc)->dup[0] = fd;
		}
	}
}

void	ft_pre_redirection(t_syntax_tree *tree, t_proc **proc)
{
	if (tree->args[0][0] == 'w' || tree->args[0][0] == 'a')
		ft_pre_write_fd(tree, proc, tree->args[0][0]);
	else if (tree->args[0][0] == 'r')
		ft_pre_read_fd(tree, proc);
	else if (tree->args[0][0] == 'h')
		ft_pre_heredoc_fd(tree, proc);
}
