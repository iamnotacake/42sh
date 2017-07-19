/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:05:02 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/18 20:05:04 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table_private.h"


void	ft_free_pth(char **pth)
{
	int	i;

	i = 0;
	while (pth[i])
	{
		free(pth[i]);
		i++;
	}
	free(pth[i]);
	free(pth);
}

void	ft_print_pth(char **pth)
{
	int	i;

	i = 0;
	while (pth[i])
	{
		ft_putendl(pth[i]);
		i++;
	}
}

t_hash	*ft_hash_table(const char *const envp[])
{
	t_hash	*new;
	char	**path;
	t_lst	*lst;

	new = NULL;
	if (!(path = ft_get_path(envp)))
		return (NULL);
	lst = ft_create_lst(path);
	// ft_print_pth(path);
	ft_free_pth(path);
	// new = (t_hash *)malloc(sizeof(t_hash));
	return (new);
}
