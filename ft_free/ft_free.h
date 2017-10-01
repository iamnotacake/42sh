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
# include "ft_free_private.h"
# include "ft_parser.h"

void	ft_free(void);
void	ft_free_syntax_tree(t_syntax_tree *tree);

#endif
