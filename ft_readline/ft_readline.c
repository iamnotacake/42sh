#include "ft_readline_private.h"

t_his			*g_history;

char			*ft_readline(const char *prompt)
{
	char		*line;

	line = NULL;
	ft_terminal_set();
	ft_putstr(prompt);
	ft_get_line(&line, &g_history);
	ft_terminal_set();
	return (line);
}
