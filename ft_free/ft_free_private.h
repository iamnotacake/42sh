#ifndef __FT_FREE_PRIVATE_H
# define __FT_FREE_PRIVATE_H
# include "ft_readline.h"
# include "ft_hash_table.h"
# include "ft_exec.h"
// #include "ft_parser.h"

void	ft_hash_free_table(void);
void	ft_free_history(void);
void	ft_free_proc(t_proc *proc);
// void	ft_free_syntax_tree(t_syntax_tree *tree);

#endif