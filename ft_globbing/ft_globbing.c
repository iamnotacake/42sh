#include <stdio.h>
#include <string.h>
#include "ft_globbing.h"

int				ft_globbing_is_pattern(const char *pattern)
{
	// TODO
	return (pattern[0] == '+');
}

void			ft_globbing_do(const char *pattern)
{
	ft_globbing_callback(strdup("SHIT1"));
	ft_globbing_callback(strdup("SHIT2"));
 	// TODO
}
