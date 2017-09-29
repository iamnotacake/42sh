/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:44:39 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 17:44:43 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LEXER_PRIVATE_H
# define __FT_LEXER_PRIVATE_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include "ft_lexer.h"

void			ft_lexer_post_string(t_token *toks);
void			ft_lexer_resolve_vars(t_token *toks);

#endif
