#include "ft_readline/ft_readline.h"
#include "ft_hash_table/ft_hash_table.h"

int		main(int argc, const char *const argv[], const char *const envp[])
{
	t_hash	*table;

	table = ft_hash_table(envp);
	char *a = ft_readline("Hello! > ");
	write(1, "\n", 1);
	puts(a);
	return (0);
}
