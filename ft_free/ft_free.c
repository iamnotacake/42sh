#include "ft_free_private.h"

void	ft_free(void)
{
	ft_hash_free_table();
	ft_free_history();
}