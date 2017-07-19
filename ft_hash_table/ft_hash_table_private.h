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

typedef struct		s_lst
{
	char			*com;
	char			*pth;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_hash
{
	struct s_lst	*list;
}					t_hash;

#endif