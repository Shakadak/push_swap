SRC	:=\
	args_to_stack.c\
	main_checker.c\
	parse_num.c

OBJ := $(OBJ) $(SRC:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(INC)
	$(COMPIL)
