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
# include "ft_free_private.h"

# define HASH_SIZE 1000


typedef struct		s_hash
{
	char			*command;
	char			*filename;
	struct s_hash	*next;
}					t_hash;

extern t_hash		**g_table;

void				ft_hash_create_lst(char **path);
void				ft_add_to_table(char *command, char *filename);
char				*ft_hash_find_command(char *command);
void				ft_hash_remove_element(char *command);
int					ft_hash_function(char *command);

#endif
