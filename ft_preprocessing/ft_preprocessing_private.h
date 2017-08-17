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

#include <stdio.h>

t_proc	*ft_pre_create_proc(void);
void	ft_pre_by_type(t_syntax_tree *tree, t_proc **proc, int *flag);
void	ft_pre_string(t_syntax_tree *tree, t_proc **proc);
void	ft_pre_print_proc(t_proc *proc);
void	ft_pre_redirection(t_syntax_tree *tree, t_proc **proc);
void	ft_pre_piped(t_syntax_tree *tree, t_proc **proc, int *flag);
void	ft_pre_bquote(t_syntax_tree *tree, t_proc **proc, int *flag);
void	ft_pre_logic(t_syntax_tree *tree, t_proc **proc, int *flag);

#endif