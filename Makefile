NAME		:= philo
CFLAGS		:= -Wextra -Wall -Werror -g3
MAKEFLAGS += --silent

# PATHS
CC			:= gcc
SRC_PATH 	:= sources
OBJ_PATH	:= objects

# SOURCES
CFILES		:= main.c

#PATH_FILES
SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))

#HEADERS
HEADERS		:= -I ./includes
HEADER_FILE := includes/philo.h

# COLORS
GREEN	:=	\033[1;32m
PURPLE	:=	\033[1;35m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

#LOADING BAR
TOTAL_FILES := $(words $(CFILES))
COMPILED_CFILES := 0

define progress_bar
	@tput cuu1
	@tput el
	@echo "$(GREEN)[========================================>] $(WHITE)($1/$(TOTAL_FILES))"
endef

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@echo "                                     "
	$(eval COMPILED_CFILES := $(shell echo $$(($(COMPILED_CFILES) + 1))))
	$(call progress_bar,$(COMPILED_CFILES),$(words $(CFILES)))

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)  ✅ The [$(GREEN)PHILOSOPHERS$(WHITE)] has been compiled! ✅ "
	@echo "$(GREEN)-------------------------------------------"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "                                     "
	@echo "$(WHITE)     Objects - $(RED)PHILOSOPHERS$(WHITE) - were cleaned!"
	@echo "                                     "

fclean: clean
	@echo "$(WHITE)              Cleaning all... 🧹"
	@echo "                                     "
	@rm -rf $(NAME)
	@echo "$(WHITE)    ✨ Cleaning - PHILOSOPHERS - complete! ✨"
	@echo "                                     "

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME)

clear:
	clear
	$(MAKE) all

re: fclean all

.PHONY: all, clean, fclean, re
