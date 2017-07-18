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

include ft_readline/files.mk
include ft_exec/files.mk
include libft/files.mk

.PHONY: all clean fclean norm

all: $(NAME)

$(NAME): $(bin)
	@ln -f $(bin) $(NAME)

$(bin): $(OBJECTS)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo -e "\033[1;35mCCLD \033[0;35m$@\033[0m"

$(obj)/%.o: %.c
	@mkdir -p $(obj)/$(shell dirname $<)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo -e "\033[1;32mCC \033[0;32m$@\033[0m"

clean:
	rm -rf build-*/obj

fclean:
	rm -rf build-* $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(HEADERS)
