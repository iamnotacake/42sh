#include "ft_readline_private.h"

char			*ft_readline(const char *prompt)
{
	return (readline(prompt));
}

void			ft_add_history(const char *command)
{
	add_history(command);
}
