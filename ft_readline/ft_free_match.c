/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 18:56:49 by olyuboch          #+#    #+#             */
/*   Updated: 2017/06/29 18:56:51 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_free_match(t_match *head)
{
	t_match	*tmp;

	while (head)
	{
		if (head->find)
			free(head->find);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
