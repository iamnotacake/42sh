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

t_hash	*table;

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

void	ft_create_table(void)
{
	// t_hash	*table;
	int		i;

	i = 0;
	table = NULL;
	if (!(table = (t_hash *)malloc(sizeof(t_hash) * (HASH_SIZE + 1))))
		return ;
	while (i <= HASH_SIZE)
	{
		table[i].lst = NULL;
		i++;
	}
}

void	ft_print_table(void)
{
	int		i;
	t_lst	*tmp;
	int		n;

	i = 0;
	while(i < HASH_SIZE)
	{
		if (table[i].lst != NULL)
		{
			ft_putstr("\n");
			tmp = table[i].lst;
			if (tmp->next)
			{
				n = 1;
				while (tmp->next)
				{
					n++;
					tmp = tmp->next;
				}
				ft_putnbr(n);
			}
			else
				ft_putstr("1");
		}
		ft_putstr("-");
		i++;
	}
	write(1, "\n", 1);
}

void	ft_hash_table(const char *const envp[])
{
	// t_hash	*table;
	char	**path;

	if (table != NULL)
		ft_hash_free_table();
	if (!(path = ft_get_path(envp, "PATH")))
		return ;
	ft_create_table();
	ft_hash_create_lst(path);	
	ft_print_table();
	ft_free_pth(path);
}
