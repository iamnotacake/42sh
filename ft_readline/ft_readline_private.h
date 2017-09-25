#ifndef FT_READLINE_H_PRIVATE
# define FT_READLINE_H_PRIVATE
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
# include "ft_readline.h"
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
void				ft_get_line(char **line, t_his **his);
void				ft_add_to_history(t_his **his, char *line);
void				ft_terminal_set(void);
void				ft_signals(void);
int					ft_count_env(char **en);
void				ft_parse_args(char **str, char ***env, t_his **his);
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
void				ft_history_find(char **lft, char **rgt, t_his *his);
void				ft_history_check(char **new, t_his *his);
void				ft_get_line(char **line, t_his **his);
void				ft_free_match(t_match *head);
void				ft_free_tmp(t_his **his);
int					ft_add_match(t_match **head, char *file);
void				ft_history_get_tory(char **lft, t_his *his);
int					ft_add_to_tmp(char **lft, char **rgt, t_his **his);
void			ft_signals(void);
void			sigint_handler(int signo);

#endif
