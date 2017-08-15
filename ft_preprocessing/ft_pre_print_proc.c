/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_print_proc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:59:49 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/15 11:59:51 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"
#include "ft_parser.h"
#include "ft_exec.h"
#include "ft_lexer.h"
#include "ft_free.h"

#include <stdio.h>

void	ft_pre_print_proc(t_proc *proc)
{
	t_proc	*tmp;
	int		i;

	tmp = proc;
	if (!tmp)
		return ;
	while (tmp->prev)
		tmp = tmp->prev;
	printf(""C034"<<LIST>>"C0"\n");
	while (tmp)
	{
		i = 0;
		while (tmp->argv[i])
		{
			printf("arg[%d]: "C033"%s"C0"\n", i, tmp->argv[i]);
			i++;
		}
		i = 0;
		while (i < 10)
		{
			if (tmp->dup[i] != i)
				printf("dup2("C031"%d, "C032"%d"C0")\n", tmp->dup[i], i);
			i++;
		}
		tmp = tmp->next;
	}
}
