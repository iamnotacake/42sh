#include "ft_free_private.h"

extern t_his	*g_history;

void	ft_free_history(void)
{
	t_his	*tmp;

	if (!g_history)
		return ;
	while (g_history->next)
		g_history = g_history->next;
	while(g_history)
	{
		tmp = g_history;
		g_history = g_history->prev;
		if (tmp->tmp)
			free(tmp->tmp);
		if (tmp->tory)
			free(tmp->tory);
		free(tmp);
	}
}
