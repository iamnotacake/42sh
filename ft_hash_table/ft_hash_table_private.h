/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:07:29 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/18 20:07:31 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_TABLE_PRIVATE_H
# define FT_HASH_TABLE_PRIVATE_H
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include "../libft/libft.h"
# define HASH_SIZE 1000

typedef struct		s_lst
{
	char			*com;
	char			*pth;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_hash
{
	struct s_lst	*lst;
}					t_hash;

t_hash				*g_table;
char				**ft_get_path(const char *const envp[], char *str);
void				ft_hash_create_lst(char **pth);
int					ft_hash_function(char *name);
// void				ft_hash_free_table(void);
char				*ft_hash_find_command(char *com);
void				ft_print_table(void);
void				ft_add_to_table(char *d_name, char *full_pth);

#endif