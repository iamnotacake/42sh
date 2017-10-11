#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    files.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvarga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/28 18:09:21 by mvarga            #+#    #+#              #
#    Updated: 2017/09/28 18:09:25 by mvarga           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS += -Ift_lexer
LDFLAGS += -ll
SOURCES += ft_lexer/lexer2.c\
			ft_lexer/ft_lexfunc.c\
			ft_lexer/ft_lexfunc2.c\
			ft_lexer/ft_lexfunc3.c\
			ft_lexer/ft_token.c \
			ft_lexer/ft_lexer_post_string.c \
			ft_lexer/ft_lexer_resolve_vars.c \
