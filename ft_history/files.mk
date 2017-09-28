# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    files.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 14:03:43 by olyuboch          #+#    #+#              #
#    Updated: 2017/09/27 14:03:45 by olyuboch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS += -Ift_history
SOURCES += ft_history/ft_history_upload.c \
			ft_history/ft_history_load.c \
			ft_history/get_next_line.c \
			ft_history/ft_history_print.c \
			ft_history/ft_history_error.c \
			ft_history/ft_history_stdout_clear.c \
			ft_history/ft_history_stdin.c \
