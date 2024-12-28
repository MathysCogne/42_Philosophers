NAME = philo

SRCDIR = src
OBJDIR = obj
INCDIR = include

SRC = philo.c \
		init/init_forks.c \
		init/init_param.c \
		init/init_philosopher.c \
\
		routines/routine_eat.c \
		routines/routine_fork.c \
		routines/routine_handler.c \
		routines/routine_sleep.c \
		routines/routine_think.c \
\
		monitor/monitor_join_thread.c \
		monitor/monitor_init.c \
		monitor/monitor_routine.c \
\
		utils/utils_clean.c \
		utils/utils_print.c \
		utils/utils_time.c \
		utils/utils_debug.c \
		utils/utils_mutex_last_meal.c \
		utils/utils_mutex_state_end.c \
\
		lib/ft_atoll.c \
		lib/ft_strlen.c \
		lib/garbage_collector.c \
		lib/is_int.c


OBJ = $(SRC:.c=.o)
SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))

BUILD = $(OBJDIR)/.build

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
# -g3
#################################
#          COMPIL MODE          #
#################################
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
  V := 
else
  V := @
endif

#################################
#             COLORS            #
#################################
RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"

#################################
#            EXECUTABLE         #
#################################

all: $(NAME)

$(NAME): $(BUILD)

$(BUILD): $(LIBFT) $(OBJ)
	@clear
	$(V)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(BONUS_OBJ) -o $(NAME)
	$(V)echo $(GREEN)"[$(NAME)] Executable created ✅"$(RESET)
	@touch $@

#################################
#        OBJ & DEP FILES        #
#################################
$(OBJDIR):
	$(V)mkdir -p $(OBJDIR) || true

DEP = $(OBJ:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

#################################
#             CLEAN             #
#################################
	
clean:
	$(V)echo $(RED)'[$(NAME)] Cleaning objects'$(RESET)
	$(V)rm -rf $(OBJDIR)

fclean: clean
	$(V)echo $(RED)'[$(NAME)] Cleaning all files'$(RESET)
	$(V)rm -f $(NAME)
	$(V)echo $(RED)'[libft] Remove directory'$(RESET)
	@rm -rf $(LIBFT_DIR)


#################################
#             NORME             #
#################################
norme:
	@if norminette | grep "Error" > norminette_errors.txt; then \
		echo $(RED)"[$(NAME)] Norme KO"$(RESET); \
		cat norminette_errors.txt | awk 'BEGIN {FS=":"; OFS=":"} \
		/^src/ || /^libft/ {print "\n" $$0} \
		/^Error/ {sub(/^Error: /, ""); print "  ➜ " $$0}'; \
	else \
		echo $(GREEN)"[$(NAME)] Norme ok ✅"$(RESET); \
	fi
	@rm -f norminette_errors.txt

#################################
#             TEST              #
#################################
test: all norme
	$(V)echo $(GREEN)"[$(NAME)] Running $(NAME) with valgrind"$(RESET)
	$(V)valgrind --leak-check=full --show-leak-kinds=all --suppressions=valgrind.supp ./$(NAME)


re: fclean all

regen:
	makemyfile

.PHONY: all clean fclean re bonus regen norme test
.DEFAULT_GOAL := all
