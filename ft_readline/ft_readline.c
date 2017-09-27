#include "ft_readline.h"

void	ft_terminal_set(void)
{
	struct termios	termios;

	tcgetattr(2, &termios);
	termios.c_lflag = (termios.c_lflag ^ ICANON) ^ ECHO;
	tcsetattr(2, TCSANOW, &termios);
}

char			*ft_readline(void)
{
	char		*line;

	line = NULL;
	ft_terminal_set();
	ft_putstr(g_promt);
	ft_get_line(&line, &g_history);
	ft_terminal_set();
	return (line);
}
