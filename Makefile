TYPE = release
prefix = build-$(TYPE)
obj = $(prefix)/obj
bin = $(prefix)/$(NAME)

CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =
SOURCES = main.c \

OBJECTS = $(addprefix $(obj)/,$(subst .c,.o,$(SOURCES)))
NAME = 42sh

ifeq ($(TYPE),release)
CFLAGS += -O3
else ifeq ($(TYPE),debug)
CFLAGS += -g
endif

include ft_hash_table/files.mk
include ft_readline/files.mk
include ft_exec/files.mk
include ft_history/files.mk
include libft/files.mk
include ft_lexer/files.mk
include ft_parser/files.mk
include ft_free/files.mk
include ft_env/files.mk
include ft_preprocessing/files.mk
include ft_globbing/files.mk
include ft_builtin/files.mk


.PHONY: all clean fclean norm

all: $(NAME)

$(NAME): $(bin)
	@ln -f $(bin) $(NAME)

$(bin): $(OBJECTS)
	@echo "\033[1;35mCCLD \033[0;35m$@\033[0m"
	@$(CC) -o $@ $^ $(LDFLAGS)

$(obj)/%.o: %.c
	@echo "\033[1;32mCC \033[0;32m$@\033[0m"
	@mkdir -p $(obj)/$(shell dirname $<)
	@$(CC) $(CFLAGS) -c -o $@ $<

%.c: %.lex
	@echo "\033[1;33mFLEX \033[0;33m$@\033[0m"
	@flex -o $@ $<

clean:
	rm -rf build-*/obj

fclean:
	rm -rf build-* $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(HEADERS)
