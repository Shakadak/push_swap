# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2017/11/27 15:38:18 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
CHECKER		:=	checker
PUSHSWAP	:=	push_swap

### DIRECTORIES ###

DIRSRC	:=	src
DIRCHK	:=	$(DIRSRC)/
DIRPS	:=	$(DIRSRC)/
DIROBJ	:=	obj
DIRINC	:=	inc
DIRLIB	:=	libft

### FILES ###

include $(DIRSRC)/src.mk

HEADPS	:=	push_swap.h
LIB		:=	libft.a

### PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))
PLIB		:=	$(DIRLIB)/$(LIB)

### COMPILATION VARIABLES ###

CC		:=	clang
C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC) -I .

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

.PHONY: all clean fclean re

all: $(CHECKER)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJ): |$(DIROBJ)

### EXECUTABLE ###

$(CHECKER): $(PLIB) $(POBJ)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(CHECKER)

re: fclean all

$(NAME): all
