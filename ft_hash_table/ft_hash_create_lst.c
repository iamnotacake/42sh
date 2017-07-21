/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_create_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:46:37 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/19 20:46:38 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table_private.h"

t_lst	*ft_new_lst(char *d_name, char *full_pth)
{
	t_lst	*new;

	new = NULL;
	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->com = ft_strdup(d_name);
	new->pth = ft_strdup(full_pth);
	new->next = NULL;
	return (new);
}

void	ft_add_to_table(char *d_name, char *full_pth)
{
	t_lst	*new;
	t_lst	*tmp;
	int		i;


	new = NULL;
	i = ft_hash_function(d_name);
	if (!(new = ft_new_lst(d_name, full_pth)))
		return ;
	if (!(table[i].lst))
		table[i].lst = new;
	else
	{
		tmp = table[i].lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_readdir(char *pth)
{
	DIR				*d;
	struct dirent	*dir;
	char			*tmp;
	char			*full_pth;

	if (!(d = opendir(pth)))
		return ;
	while ((dir = readdir(d)))
	{
		tmp = ft_strjoin(pth, "/");
		full_pth = ft_freejoin(tmp, dir->d_name, 1);
		if (access(full_pth, X_OK) == 0 && (dir->d_type == 8 || dir->d_type == 10))
			ft_add_to_table(dir->d_name, full_pth);
		free(full_pth);
	}
	closedir(d);
}

void	ft_hash_create_lst(char **pth)
{
	int		i;

	i = 0;
	while (pth[i])
	{
		ft_readdir(pth[i]);
		i++;
	}
}
