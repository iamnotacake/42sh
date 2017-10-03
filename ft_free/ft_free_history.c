/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:31:55 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/10/01 15:31:58 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

extern t_his	*g_history;

void	ft_free_history(void)
{
	t_his	*tmp;

	if (!g_history)
		return ;
	while (g_history->next)
		g_history = g_history->next;
	while (g_history)
	{
		tmp = g_history;
		g_history = g_history->prev;
		if (tmp->tmp)
			free(tmp->tmp);
		if (tmp->tory)
			free(tmp->tory);
		free(tmp);
	}
}
