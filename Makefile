# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/19 16:02:15 by jalvaro           #+#    #+#              #
#    Updated: 2020/05/25 01:43:16 by jalvaro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = libft.a

FILES = ft_printf ft_printf_utils1 ft_printf_utils2 ft_put_utils1	\
		ft_put_utils2 ft_put_d ft_put_c ft_put_s ft_put_u ft_put_p	\
		ft_put_x ft_put_perc 

SRC_DIR = ./srcs/
SRC_FILE = $(FILES:=.c)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_TEMP = $(addprefix $(SRC_DIR), %.c)

OBJ_DIR = ./obj/
OBJ_FILE = $(FILES:=.o)
OBJ = $(addprefix $(OBJ_DIR), $(FILES:=.o))
OBJ_TEMP = $(addprefix $(OBJ_DIR), %.o)

INCLUDES = ./includes/
HEADER = $(addprefix $(INCLUDES), ft_printf.h)

LIB_DIR = ./srcs/libft/
LIB_FILE = $(addprefix $(LIB_DIR), $(LIB))
INCLUDES_LIB = ./srcs/libft/includes/
HEADER_LIB = $(addprefix $(INCLUDES_LIB), libft.h)

all: $(LIB) $(NAME) $(SRC)

$(NAME): $(OBJ_DIR) $(OBJ)
	@cp $(LIB_FILE) ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Библиотека $(NAME) готова

$(OBJ_TEMP): $(SRC_TEMP) $(HEADER_LIB) $(LIB_FILE) $(HEADER)
	@gcc -c -Wall -Werror -Wextra -I $(INCLUDES) -I $(INCLUDES_LIB) $< -o $@
	@echo Собираю $@ из $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(LIB):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory

clean: 
	@$(MAKE) fclean -C $(LIB_DIR) --no-print-directory
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo libftprintf: удаляю *.o

fclean: clean
	@rm -f libftprintf.a
	@echo libftprintf: Все очищено

re: fclean all

.PHONY: all clean fclean re
