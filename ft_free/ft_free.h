/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:35:22 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/10/01 15:35:25 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FREE_H
# define __FT_FREE_H
# include "ft_parser.h"
# include "ft_readline.h"
# include "ft_hash_table.h"
# include "ft_exec.h"

void	ft_free(void);
void	ft_free_syntax_tree(t_syntax_tree *tree);
void	ft_free_hash_table(void);
void	ft_free_history(void);
void	ft_free_proc(t_proc **proc);
void	ft_free_mas(char **sp);


#endif
