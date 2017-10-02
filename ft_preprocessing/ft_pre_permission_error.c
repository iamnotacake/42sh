/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_permission_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:48:35 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/06 16:48:37 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

void	ft_pre_permission_error(t_syntax_tree *tree, t_proc **proc)
{
	ft_free_proc(proc);
	*proc = NULL;
	write(2, "wtf: permission denied: ", 24);
	ft_putendl(tree->args[1]);
}
