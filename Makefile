# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2017/11/27 11:58:11 by npineau          ###   ########.fr        #
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

include $(DIRCLI)/sources.mk
include $(DIRSRV)/sources.mk

HEADCLI	:=	client.h
HEADSRV	:=	server.h
LIB		:=	libft.a

### PATHS ###

POBJCLI		:=	$(addprefix $(DIROBJ)/, $(OBJCLI))
POBJSRV		:=	$(addprefix $(DIROBJ)/, $(OBJSRV))
PHEADSRV	:=	$(DIRINC)/$(HEADSRV)
PHEADCLI	:=	$(DIRINC)/$(HEADCLI)
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

all: $(SERVEUR) $(CLIENT)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJSRV): |$(DIROBJ)

$(POBJCLI): |$(DIROBJ)

### EXECUTABLE ###

$(CLIENT): $(PLIB) $(POBJCLI)
	$(LINK)

$(SERVEUR): $(PLIB) $(POBJSRV)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVEUR)

re: fclean all

$(NAME): all
