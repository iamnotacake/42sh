/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:09:44 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 16:09:46 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <string.h>
# include "ft_readline.h"
# include "ft_hash_table.h"
# include "ft_lexer.h"
# include "ft_parser.h"
# include "ft_env.h"
# include "ft_free.h"
# include "ft_preprocessing.h"
# include "ft_history.h"
# include "ft_signals.h"
# include "libft/libft.h"

char	*ft_join_quote(char *a, char *b);
void	ft_print_t_token(t_token *lst);

#endif
