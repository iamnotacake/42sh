/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigtstp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 19:29:56 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/29 19:29:57 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

void	sigtstp_handler(int signo)
{
	t_list *last;
	t_list *elem;

	(void)signo;
	if (g_parent && g_proc)
	{
		last = g_jobs;
		elem = ft_lstnew(NULL, 0);
		elem->content = g_proc;
		while (last->next)
		{
			if (last->content_size == 1)
				last->content_size = 2;
			last = last->next;
		}
		last->next = elem;
		elem->prev = last;
	}
}
