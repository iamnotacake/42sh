/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:54:20 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/01 16:54:20 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin_private.h"

static void	print_job(int num, t_list *entry)
{
	ft_putstr("[");
	ft_putnbr(num);
	ft_putstr("] ");
	if (entry->content_size == 1)
		ft_putstr("+ suspended");
	else if (entry->content_size == 2)
		ft_putstr("- suspended");
	else
		ft_putstr("  suspended");
	ft_putchar('\t');
	ft_putstr(((t_proc *)entry->content)->argv[1]);
	write(1, "\n", 1);
}

int			ft_build_jobs(char **env, char **argv)
{
	t_list	*last;
	int		i;

	(void)env;
	(void)argv;
	last = g_jobs;
	if (last)
	{
		i = 1;
		while (last)
		{
			print_job(i, last);
			last = last->next;
		}
	}
	return (0);
}
