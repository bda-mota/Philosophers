NAME		:= philo
CFLAGS		:= -Wextra -Wall -Werror -pthread -O3
MAKEFLAGS += --silent
# -fsanitize=thread
# PATHS
CC			:= gcc
OBJ_PATH	:= objects

# SOURCES
CFILES		:= main.c init.c parsing.c utils.c threads.c routine.c routine_utils.c monitor.c print.c

#PATH_FILES
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))

#HEADERS
HEADERS		:= -I.

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
	@echo "$(GREEN)[================================>] $(WHITE)($1/$(TOTAL_FILES))"
endef

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: %.c philo.h | $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@echo "                                     "
	$(eval COMPILED_CFILES := $(shell echo $$(($(COMPILED_CFILES) + 1))))
	$(call progress_bar,$(COMPILED_CFILES),$(words $(CFILES)))

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)-----------------------------------"
	@echo "$(WHITE)   🍝 The [$(GREEN)DINNER$(WHITE)] is served! 🍝 "
	@echo "$(GREEN)-----------------------------------"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "                                     "
	@echo "$(WHITE)     Objects - $(RED)PHILOSOPHERS$(WHITE) - were cleaned!"
	@echo "                                     "

fclean: clean
	@echo "$(WHITE)                 Cleaning all... 🧹"
	@echo "                                     "
	@rm -rf $(NAME)
	@echo "$(WHITE)   ✨ Cleaning - PHILOSOPHERS - complete! ✨"
	@echo "                                     "

val: $(NAME)
	valgrind --tool=helgrind --tool=drd ./$(NAME) $(ARGS)

clear:
	clear
	$(MAKE) all

re: fclean all

.PHONY: all clean fclean re
