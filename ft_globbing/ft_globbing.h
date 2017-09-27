#ifndef __FT_GLOBBING
# define __FT_GLOBBING

# include <stdlib.h>
# include <string.h>
# include "ft_parser.h"
# include <dirent.h>
# include "ft_env.h"
#include "libft.h"

#define U(c) ((c) & 0377)

void			ft_globbing_call(t_syntax_tree *arguments);
void			ft_globbing_callback(char *str);
int				ft_globbing_is_pattern(char *pattern);
int 			ft_match(char *s, char *p, int cur_char, int c);
int				ft_brackets(char **p, int cur_char);

#endif
