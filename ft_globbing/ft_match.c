#include "ft_globbing.h"

static	int			ft_match2(char *s, char *p, int cur_char, int c)
{
	if (c == '*')
	{
		if (!*p)
			return (1);
		s--;
		while (*s)
			if (ft_match(s++, p, 0 , 0))
				return (1);
		return (0);
	}
	else if (c == 0)
		return ((cur_char == 0));
	else if (c != '?')
	{
		if (c != cur_char)
			return (0);
		return (-1) ;
	}
	else if (c == '?')
	{
		if (cur_char == 0)
			return (0);
		return (-1) ;
	}
	return (-2);
}

int 				ft_match(char *s, char *p, int cur_char, int c)
{
	int				flag;
	
	while (1)
	{
		cur_char = *s++;
		c = U (*p++);
		if (c == '\\')
		{
			c = U (*p++);
			if (c == 0 || c != cur_char)
				return (0);
			continue ;
		}
		else if (c == '[')
		{
			if (!ft_brackets(&p, cur_char))
				return (0);
			continue ;
		}
		if ((flag = ft_match2(s, p, cur_char, c)) == -1)
			continue ;
		if (flag != -2)
			return (flag);
	}
	return (0);
}