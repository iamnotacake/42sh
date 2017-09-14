/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_standart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:52:35 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 14:52:37 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec_private.h"

int	ft_exec_standart(t_proc **proc)
{
	int		status;

	// printf("<<GO>>\n");
	status = 0;
	if ((status = ft_exec_command_access(proc)) != 0)
		return (-1);
	return (status);
}
