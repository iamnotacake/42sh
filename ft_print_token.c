
#include "shell.h"

void	ft_print_t_token(t_token *lst)
{
	t_token	*beg;

	beg = lst;
	ft_putstr("\n");
	while (beg)
	{
		ft_putstr(beg->data);
		ft_putstr("->");
		beg = beg->next;
	}
	ft_putstr("\nmatch:\n");
	beg = lst;
	while (beg)
	{
		ft_putstr(beg->match);
		ft_putstr("->");
		beg = beg->next;
	}
}
