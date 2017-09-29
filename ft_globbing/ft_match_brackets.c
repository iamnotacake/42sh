/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_brackets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:46:56 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 17:06:57 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_globbing.h"

int g_ok;
int g_notflag;
int g_cc;
int g_lc;

static int			ft_syinsy(unsigned int smin, \
unsigned int smy, unsigned int smax)
{
	char			left[2];
	char			right[2];
	char			middle[2];

	left[0] = smin;
	left[1] = '\0';
	right[0] = smax;
	right[1] = '\0';
	middle[0] = smy;
	middle[1] = '\0';
	return (ft_strcmp(left, middle) <= 0 && ft_strcmp(middle, right) <= 0);
}

static int			ft_brackets3(char **p, int cur_char)
{
	if (g_cc == '\\')
	{
		g_cc = U(*(*p)++);
		if (!g_cc)
			return (0);
	}
	if (g_notflag)
	{
		g_lc = g_cc;
		if (cur_char && cur_char != g_lc)
			g_ok++;
		else
			return (0);
	}
	else
	{
		g_lc = g_cc;
		if (cur_char == g_lc)
			g_ok++;
	}
	return (1);
}

static int			ft_brackets2(char **p, int cur_char)
{
	if (g_cc == '-')
	{
		if (g_notflag)
		{
			if (!ft_syinsy(g_lc, cur_char, U(*(*p)++)))
				g_ok++;
			else
				return (0);
		}
		else
		{
			if (ft_syinsy(g_lc, cur_char, U(*(*p)++)))
				g_ok++;
		}
	}
	return (1);
}

static int			ft_brackets_loop(char **p, int cur_char)
{
	while ((g_cc = U(*(*p)++)))
	{
		if (g_cc == ']')
		{
			if (g_ok)
				break ;
			return (0);
		}
		if (!ft_brackets2(p, cur_char))
			return (0);
		else if (!ft_brackets3(p, cur_char))
			return (0);
	}
	return (1);
}

int					ft_brackets(char **p, int cur_char)
{
	g_lc = 077777;
	g_ok = 0;
	g_notflag = 0;
	if (*(*p) == '!')
	{
		g_notflag = 1;
		(*p)++;
	}
	if (!ft_brackets_loop(p, cur_char))
		return (0);
	if (g_cc == 0)
		return (0);
	return (1);
}
