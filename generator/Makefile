##
## EPITECH PROJECT, 2019
## <project>
## File description:
## [file description]
##


### SOURCES ###
#----c_sources----#
SRC			:= main.c
SRC			+=
SRC			+=
#----tests_sources----#
UT_SRC		:= test_main.c
UT_SRC		+=
### SOURCES ###


### DIRECTORIES ###
#----c_sources_dir----#
SRC_DIR		:=	./src/
#----unit_tests_sources_dir----#
UT_DIR		:=	./tests/
#----headers_sources_dir----#
INC_DIR		:=	./include/
### DIRECTORIES ###


### COMPILE_USEFULL ###
#----project_usefull----#
NAME		=	generator
DEBUG_NAME	=	debug
CFLAGS		:=	-Wall -Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-iquote $(INC_DIR)
SRC_PATH	=	$(addprefix $(SRC_DIR), $(SRC))
#----unit_test_usefull----#
UT_NAME		=	testbin
UT_FLAGS	=	--coverage -lcriterion
UT_PATH		=	$(addprefix $(UT_DIR), $(UT_SRC))
#----general_usefull----#
CC			=	gcc
OBJ			=	$(SRC_PATH:.c=.o)
### COMPILE_USEFULL ###


### COLOURS ###
CRESET      :=  $$'\033[0m'
#----\033[38;2;<R>;<G>;<B>m----#
CLIGHTGREEN :=  $$'\033[38;2;190;255;200m'
#----format----#
CBOLD       :=  $$'\033[1m'
### COLOURS ###


### RULES_USEFULL ###
RM			=	rm -f
### RULES_USEFULL ###


#------------------------------------------------------------#
.PHONY:		all
all:		$(NAME)
$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
			@ echo $(CLIGHTGREEN) $(CBOLD) "# COMPILE SUCCESSFULL #"$(CRESET)

#------------------------------------------------------------#
.PHONY:		debug
debug:		$(DEBUG_NAME)
$(DEBUG_NAME):	$(OBJ)
			$(CC) -g3 $(CFLAGS) -o $(DEBUG_NAME) $(OBJ)
			@ echo $(CLIGHTGREEN) $(CBOLD) "# COMPILE SUCCESSFULL #"$(CRESET)

#------------------------------------------------------------#
.PHONY:		clean
clean:
			$(RM) $(OBJ)
			$(RM) *.gc*

#------------------------------------------------------------#
.PHONY:		fclean
fclean:		clean
			$(RM) $(NAME)
			$(RM) $(DEBUG_NAME)
			$(RM) $(UT_NAME)

#------------------------------------------------------------#
.PHONY:		re
re:			fclean all
