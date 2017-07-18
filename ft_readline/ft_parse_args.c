/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:55:51 by olyuboch          #+#    #+#             */
/*   Updated: 2017/03/29 16:55:52 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

// t_dt	*ft_do_now(char **str, char **env, t_his **his)
// {
// 	char	*tmp;
// 	t_dt	*lt;
// 	t_dt	*tp;

// 	lt = NULL;
// 	ft_check_on_quotes(str, his);
// 	tmp = ft_strdup((*str));
// 	write(1, "\n", 1);
// 	if (!(lt = ft_create_lt(tmp, env)))
// 	{
// 		free(tmp);
// 		return (NULL);
// 	}
// 	free(tmp);
// 	tp = lt;
// 	if (!ft_check_on_pipes(tp))
// 	{
// 		ft_putstr_fd("21sh: to match pipes or redirections", 2);
// 		ft_putstr_fd(" near each other!\n", 2);
// 		return (NULL);
// 	}
// 	return (lt);
// }

// void	out_pp(t_dt *lt)
// {
// 	t_dt	*tm;

// 	tm = lt;
// 	while (tm)
// 	{
// 		ft_putendl(tm->str);
// 		tm = tm->next;
// 	}
// }

void	ft_parse_args(char **str, char ***env, t_his **his)
{

	if (*env[0] && *his)
		write(1, "\n", 1);
	ft_putendl(*str);
	// t_sep	*sep;
	// t_sep	*tmp;
	// t_dt	*lt;
	// t_dt	*pp;

	// if (!(*str))
	// 	return ;
	// if (!(lt = ft_do_now(str, *env, his)))
	// 	return ;
	// pp = lt;
	// sep = ft_create_sep(pp);
	// if (pp)
	// 	ft_free_lt(pp);
	// tmp = sep;
	// ft_go_ahead(tmp, env, his);
	// ft_free_sep(sep);
}
