#include "ft_readline/ft_readline.h"
#include "ft_hash_table/ft_hash_table.h"

int		main(int argc, const char *const argv[], const char *const envp[])
{
	char	*pth;

	g_table = NULL;
	ft_hash_table(envp);
	char *a = ft_readline("Hello! > ");
	write(1, "\n", 1);
	puts(a);
	pth = ft_hash_find_command(a);
	printf("\n%s\n", pth);
	if (pth)
		free(pth);
	ft_hash_free_table();
	if (a)
		free(a);
	sleep(10);
	return (0);
}
