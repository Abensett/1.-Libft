
# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #

GREEN		= \033[32;1m
RED			= \033[31;1m
YELLOW		= \033[33;1m
CYAN		= \033[36;1m
RESET		= \033[0m
WHITE 		= \033[0;m

# **************************************************************************** #
#                     PROJECT'S EXECUTABLE AND DIRECTORIES                     #
# **************************************************************************** #

NAME			= libft.a

DIRSRC			= src/

DIROBJ			= obj/

# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

# Debug flag, use with 'make DEBUG=1'
ifeq ($(DEBUG), 1)
	CFLAGS		+= -g
endif

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRC_FILES = ft_abs.c \
	ft_atol.c \
	ft_atoll.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_double_abs.c \
	ft_double_pow.c\
	ft_isalnum.c \
	ft_isdigit.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c\
	ft_memset.c \
	ft_min.c \
	ft_putchar_fd.c\
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_substr.c \
	ft_tab_long_print.c \
	ft_tab_int_print.c \
	ft_tab_long_sort.c \
	ft_tab_str_print.c \
	ft_tolower.c \
	ft_toupper.c \


SRCBONUS_FILES = ft_lstnew.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c \
	  ft_lstfree.c \
	  ft_lstmap.c \
	  ft_lst_int_print.c \
	  ft_lst_int_search.c \
	  ft_lst_int_search_index.c \
	  ft_lst_int_occurence.c \
	  ft_lst_int_check_order.c \
	  ft_lst_get_median.c \
	  ft_lst_long_check_order.c \
	  ft_lst_long_fill.c \
	  ft_lst_str_print.c \


# Inutile ici
SRC = $(addprefix src/, $(SRC_FILES))

SRCBONUS = $(addprefix src/, $(SRCBONUS_FILES))

# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #

OBJ 		= 		$(SRC_FILES:.c=.o)
OBJ		:= 		$(addprefix ${DIROBJ},${OBJ})

OBJBONUS 	= 		$(SRCBONUS_FILES:.c=.o)
OBJBONUS	:= 		$(addprefix ${DIROBJ},${OBJBONUS})

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@printf "\n[$(GREEN)OK$(WHITE)] $(NAME)📙 generated \n"

bonus:		$(OBJBONUS)
			@ar rc $(NAME) $(OBJBONUS)
			@printf "\n[$(GREEN)OK$(WHITE)] $(NAME)📙 🅱️  generated \n"

$(DIROBJ)%.o:$(DIRSRC)%.c
			@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛ \n"
			@mkdir -p $(DIROBJ)
			@$(CC) $(CFLAGS) -c $< -o $@
			@printf "\n[$(GREEN)OK$(WHITE)] $(<) generated \n"
clean:
			@rm -rf $(OBJ)	$(OBJSBONUS) $(DIROBJ)
			@printf "\n[$(GREEN)cleaned$(WHITE)] .o FILES \n"

fclean:		clean
			@rm -rf $(NAME)
			@printf "\n[$(GREEN)cleaned$(WHITE)] $(NAME) \n"

re:			fclean all

.PHONY: all clean fclean re
