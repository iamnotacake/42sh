/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing_private.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 09:34:20 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/05 09:34:22 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PREPROCESSING_PRIVATE_H
# define  __FT_PREPROCESSING_PRIVATE_H
# include "ft_parser.h"
# include "ft_exec.h"
# include "ft_lexer.h"
# include "ft_free.h"

void	ft_pre_add_arg(t_syntax_tree *tree, t_proc **proc);
void	ft_pre_expression(t_syntax_tree *tree);
void	ft_pre_print_proc(t_proc *proc);
void	ft_pre_add_redir(t_syntax_tree *tree, t_proc **proc);

#endif