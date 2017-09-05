/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:23:00 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/05 11:23:03 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

void	ft_pre_exec(t_proc **proc)
{
	if (!(*proc))
		return ;
	printf("EXECVE\n");
	ft_pre_print_proc(*proc);
	ft_exec(proc);
	ft_free_proc(*proc);
	*proc = NULL;
}
