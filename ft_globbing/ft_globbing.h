#ifndef __FT_GLOBBING
# define __FT_GLOBBING

# include <stdlib.h>
# include <string.h>
# include "ft_parser.h"

void			ft_globbing_call(t_syntax_tree *arguments);
void			ft_globbing_callback(char *str);

int				ft_globbing_is_pattern(const char *pattern);
void			ft_globbing_do(const char *pattern);

#endif
