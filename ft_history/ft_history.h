/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:04:05 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:28:42 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HISTORY_H
# define FT_HISTORY_H

# include <stdio.h>
# include "ft_readline.h"
# include "ft_builtin.h"
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define GNL_END 0
# define GNL_ERR -1
# define GNL_INSIDE 1
# define BUFF 32

extern char		**g_env_g;

typedef struct	s_fd
{
	int			fd;
	char		*s_tmp;
	struct s_fd	*next;
}				t_fd;

extern t_his	*g_history;
void			ft_history_upload(void);
void			ft_history_load(char *str, int fl);
int				get_next_line(const int fd, char **line);
int				ft_history_print(t_proc **proc);
void			ft_history_error(t_proc **proc, char *er);
int				ft_history_stdout_clear(t_proc **proc);
int				ft_history_stdin(t_proc **proc);
t_his			*ft_history_up(void);
t_his			*ft_history_dwn(void);

#endif
