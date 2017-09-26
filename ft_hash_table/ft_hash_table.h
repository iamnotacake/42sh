/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 19:47:45 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/18 19:47:48 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_HASH_TABLE_H
# define __FT_HASH_TABLE_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include "../libft/libft.h"

# define HASH_SIZE 1000

typedef struct		s_hash
{
	char			*command;
	char			*filename;
	struct s_hash	*next;
}					t_hash;

t_hash				**ft_hash_table(const char *const envp[]);
void				ft_hash_add(t_hash **table, char *command, \
																char *filename);
void				ft_hash_remove(t_hash **table, char *command);
char				*ft_hash_find(t_hash **table, char *command);

#endif
