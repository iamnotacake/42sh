#include "ft_readline/ft_readline.h"

int		main(int argc, const char *const argv[], const char **envp)
{
	
	char *a = ft_readline("Hello! > ");
	puts(a);
	return (0);
}
