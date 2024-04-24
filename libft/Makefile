# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 13:59:33 by cfidalgo          #+#    #+#              #
#    Updated: 2024/04/09 17:31:36 by cfidalgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========# COLORS #==========#
DEF_COLOR = \033[0m
WHITE_BOLD = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m
#==============================#


#===========# NAME #===========#
NAME = libft.a
#==============================#


#=========# COMMANDS #=========#
AR = ar
ARFLAGS = rcs

CC = GCC
CFLAGS = -Wall -Wextra -Werror

RMRF = rm -rf
MKDIR = mkdir -p
#==============================#


#===========# DIRS #===========#
INC = ./
BINC = ./
OBJS_DIR = bin/
SRC_DIR = ./
BSRC_DIR = ./
#==============================#


#===========# FILE #===========#
FILES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		ft_printf.c \
		handle_flags_helpers.c \
		print_complex_helpers.c \
		print_complex_utils.c \
		print_global_helpers.c \
		print_numbers_helpers.c \
		print_raw_utils.c \
		print_simple_helpers.c \
		print_simple_utils.c \
		print_string_helpers.c

BONUS_FILES = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
#==============================#


#===========# SRCS #===========#
SRC = $(addprefix $(SRC_DIR), $(FILES))

BONUSSRC = $(addprefix $(BSRC_DIR), $(BONUS_FILES))
#==============================#


#===========# OBJS #===========#
OBJS = $(addprefix $(OBJS_DIR), $(FILES:.c=.o))

BONUSOBJS = $(addprefix $(OBJS_DIR), $(BONUS_FILES:.c=.o))
#==============================#


#===========# DEPS #===========#
DEPS = $(OBJS:.o=.d)

BONUSDEPS = $(BONUSOBJS:.o=.d)
#==============================#


#============ RULE ============#
all: $(NAME)


ifndef BFLAG
$(NAME):: $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)	
else
$(NAME):: $(OBJS) $(BONUSOBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUSOBJS)
endif


$(OBJS_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(OBJS_DIR)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@echo "$(YELLOW)Compiling object $(PINK)$<$(YELLOW)...$(DEF_COLOR)"


$(OBJS_DIR)%.o: $(BSRC_DIR)%.c Makefile
	@$(MKDIR) $(OBJS_DIR)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@echo "$(YELLOW)Compiling object $(PINK)$<$(YELLOW)...$(DEF_COLOR)"


clean:
	@$(RMRF) $(OBJS_DIR)


fclean: clean
	@$(RMRF) $(NAME)


re: fclean all


bonus:
	@$(MAKE) --no-print-directory BFLAG=1
#==============================#


#=========== EXTRAS ===========#
.PHONY: all clean fclean re bonus

-include $(DEPS)
-include $(BONUSDEPS)
#=========== EXTRAS ===========#
