/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:40:29 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/03 16:40:31 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_join_quote(char *a, char *b)
{
	char *res;

	res = malloc(ft_strlen(a) + 1 + ft_strlen(b ? b : "") + 1);
	ft_strcpy(res, a);
	ft_strcat(res, "\n");
	ft_strcat(res, b ? b : "");
	free(a);
	free(b);
	return (res);
}
