#ifndef __FT_GLOBBING
# define __FT_GLOBBING

# include <stdlib.h>
# include <string.h>
# include "ft_parser.h"

void			ft_globbing_call(t_syntax_tree *arguments);

int				ft_globbing_init(const char *pattern);
char			*ft_globbing_next(void);

#endif
