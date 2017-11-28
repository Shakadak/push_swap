SRC	:=\
	args_to_stack.c\
	get_program.c\
	main_checker.c\
	parse_num.c

OBJ := $(OBJ) $(SRC:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(INC)
	$(COMPIL)
