
#ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <string.h>
#include "ft_readline.h"
#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_env.h"
#include "ft_free.h"
#include "ft_preprocessing.h"

void	ft_hash_table(const char *const envp[]);
char	*ft_hash_find_command(char *command);
void	ft_add_to_table(char *command, char *filename);
void	ft_hash_remove_element(char *command);

#endif /* shell_h */
