/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_find_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:59:04 by olyuboch          #+#    #+#             */
/*   Updated: 2017/06/29 17:59:06 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

int		ft_add_match(t_match **head, char *file)
{
	t_match	*new;
	t_match	*tmp;

	if (!(new = (t_match *)malloc(sizeof(t_match))))
		return (0);
	new->find = ft_strdup(file);
	new->next = NULL;
	if (!(*head))
		(*head) = new;
	else
	{
		tmp = (*head);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

t_match	*ft_tab_find_file(char *cut, DIR *d)
{
	struct dirent	*dir;
	int				l;
	t_match			*head;

	l = ft_strlen(cut);
	head = NULL;
	while ((dir = readdir(d)))
	{
		if (!ft_strncmp(cut, dir->d_name, l))
		{
			if (!ft_add_match(&head, dir->d_name))
			{
				closedir(d);
				return (NULL);
			}
		}
	}
	closedir(d);
	return (head);
}
