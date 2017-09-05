#include "ft_globbing.h"

int				ft_globbing_init(const char *pattern)
{
	// If `pattern` is something that has *, , etc:
	// 	 init some global structure with *copy* of that pattern
	// 	 return 1
	// else
	//   return 0
	return (0);
}

char			*ft_globbing_next(void)
{
	// Using that global structure, find files.
	// Every time this function called, it must return one mathing filename.
	// If there are no more files, do some cleanup and return NULL
	return (NULL);
}
