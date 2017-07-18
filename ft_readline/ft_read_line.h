/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:29:52 by olyuboch          #+#    #+#             */
/*   Updated: 2017/04/22 16:29:54 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M21SH_H
# define M21SH_H
# define BUFF_SIZE 100
# define READ_SIZE 16
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include "../libft/libft.h"
# define CTRU "\033[1;5A"
# define CTRD "\033[1;5B"
# define PIPE 1
# define RDOR 2
# define RDTR 3
# define RDOL 4
# define RDTL 5
# define FLOW 6


typedef struct		s_his
{
	char			*tory;
	char			*tmp;
	struct s_his	*prev;
	struct s_his	*next;
}					t_his;

typedef struct		s_match
{
	char			*find;
	struct s_match	*next;
}					t_match;

typedef struct		s_focu
{
	char			*fold;
	char			*cut;
}					t_focu;

void				ft_signals(void);
void				ft_start(char **env);
void				ft_parse_args(char **str, char ***env, t_his **his);
void				ft_get_line(char **line, t_his **his);
void				ft_get_line_save(char **lft, char **rgt, char **line,
					t_his **his);
void				ft_move_cursor(char **lft, char **rgt, char *buf);
void				ft_move_cursor_left(char **lft, char **rgt);
void				ft_move_cursor_right(char **lft, char **rgt, int len);
void				ft_move_history(char *buf, char **lft, char **rgt,
					t_his **his);
void				ft_move_backslash(char **lft, char **rgt);
void				ft_move_begin_end(char **lft, char **rgt, char *buf);
void				ft_move_end(char **lft, char **rgt, int len);
void				ft_move_words(char **lft, char **rgt, char *buf);
void				ft_move_word_right(char **lft, char **rgt, int len);
void				ft_move_line(char **lft, char **rgt, char *buf);
void				ft_move_line_down(char **lft, char **rgt, int len);
void				ft_move_tab(char **lft, char **rgt);
void				ft_tab_cut(char **lft, int sp, int l);
t_match				*ft_tab_find_file(char *cut, DIR *d);
int					ft_tab_match_get(t_match *mat);
void				ft_tab_print_match(char *fold, char *cut, char **lft);
void				ft_tab_try_to_paste(t_focu *fo, char *find,
					int num, char **lft);

#endif
