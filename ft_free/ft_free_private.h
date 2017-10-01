/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:30:46 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/10/01 15:30:51 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FREE_PRIVATE_H
# define __FT_FREE_PRIVATE_H
# include "ft_readline.h"
# include "ft_hash_table.h"
# include "ft_exec.h"

/*
**#include "ft_parser.h"
*/

void	ft_hash_free_table(void);
void	ft_free_history(void);
void	ft_free_proc(t_proc *proc);
void	ft_free_mas(char **sp);

/*
**void	ft_free_syntax_tree(t_syntax_tree *tree);
*/

#endif
