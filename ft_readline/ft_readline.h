/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:00:13 by alischyn          #+#    #+#             */
/*   Updated: 2017/10/01 16:00:55 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_READLINE_H
# define __FT_READLINE_H
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
# define ARRL "\033[D"
# define ARRR "\033[C"
# define ARRU "\033[A"
# define ARRD "\033[B"
# define ALTU "\033\033[A"
# define ALTD "\033\033[B"
# define ALTR "\033\033[C"
# define ALTL "\033\033[D"
# define SHTL "\033[1;2D"
# define SHTR "\033[1;2C"
# define PIPE 1
# define RDOR 2
# define RDTR 3
# define RDOL 4
# define RDTL 5
# define FLOW 6
# define ESC 0x1B
# define K_UP 0x415B
# define K_DWN 0x425B
# define K_RGT 0x435B
# define K_LFT 0x445B
# define K_DEL 0x7E335B
# define K_BACKSP 0x7F
# define K_CTR_R 0x12
# define K_ALT_LFT 0x445b1b
# define K_ALT_RGT 0x435b1b
# define K_ALT_UP 0x415b1b
# define K_ALT_DWN 0x425b1b
# define K_ALT_BEG 0x48393b315b
# define K_ALT_END 0x46393b315b
# define K_SHT_LFT 0x44323b315b
# define K_SHT_RGT 0x43323b315b

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

typedef struct		s_his
{
	char			*tory;
	char			*tmp;
	struct s_his	*prev;
	struct s_his	*next;
}					t_his;

extern char			*g_promt;
extern t_his		*g_history;

char				*ft_readline();
void				ft_get_line(char **line, t_his **his);
void				ft_add_to_history(t_his **his, char *line);
void				ft_terminal_set(void);
int					ft_count_env(char **en);
void				ft_parse_args(char **str, char ***env, t_his **his);
void				ft_get_line_save(char **lft, char **rgt, char **line,
					t_his **his);
void				ft_move_cursor(char **lft, char **rgt, unsigned long key);
void				ft_move_cursor_left(char **lft, char **rgt);
void				ft_move_cursor_right(char **lft, char **rgt, int len);
void				ft_move_history(unsigned long key, char **lft, char **rgt,
					t_his **his);
void				ft_move_backslash(char **lft, char **rgt);
void				ft_move_begin_end(char **lft, char **rgt,
										unsigned long key);
void				ft_move_end(char **lft, char **rgt, int len);
void				ft_move_words(char **lft, char **rgt, unsigned long key);
void				ft_move_word_right(char **lft, char **rgt, int len);
void				ft_move_line(char **lft, char **rgt, unsigned long key);
void				ft_move_line_down(char **lft, char **rgt, int len);
void				ft_move_tab(char **lft, char **rgt);
void				ft_tab_cut(char **lft, int sp, int l);
t_match				*ft_tab_find_file(char *cut, DIR *d);
int					ft_tab_match_get(t_match *mat);
void				ft_tab_print_match(char *fold, char *cut, char **lft);
void				ft_tab_try_to_paste(t_focu *fo, char *find,
					int num, char **lft);
void				ft_history_find(char **lft, char **rgt, t_his *his);
void				ft_history_check(char **new, t_his *his);
void				ft_get_line(char **line, t_his **his);
int					ft_get_line_is_exit(char **line);
void				ft_free_match(t_match *head);
void				ft_free_tmp(t_his **his);
int					ft_add_match(t_match **head, char *file);
void				ft_history_get_tory(char **lft, t_his *his);
int					ft_add_to_tmp(char **lft, char **rgt, t_his **his);
void				ft_history_down(t_his **his);
int					ft_char_analysis(unsigned char key, char **lft,
									char **rgt, t_his **his);

#endif
