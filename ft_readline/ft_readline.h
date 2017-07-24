#ifndef __FT_READLINE_H
# define __FT_READLINE_H

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

char				*ft_readline(const char *prompt);

#endif
