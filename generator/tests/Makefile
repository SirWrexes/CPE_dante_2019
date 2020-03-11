##
## EPITECH PROJECT, 2019
## <project>
## File description:
## [file description]
##

### SOURCES ###
#----c_sources----#
SRC			:=	ft_revstr.c
SRC			+=	ft_strlen.c
#----tests_sources----#
UT_SRC		:=	test_ft_revstr.c
UT_SRC		+=	test_ft_strlen.c
### SOURCES ###


### DIRECTORIES ###
#----c_sources_dir----#
SRC_DIR		:=	../lib/src/
#----unit_tests_sources_dir----#
UT_DIR		:=	./lib_tests/
#----headers_sources_dir----#
INC_DIR		:=	../lib/include/
### DIRECTORIES ###

### COMPILE_USEFULL ###
#----project_usefull----#
NAME		=	lib_tbin
CFLAGS		:=	-Wall -Wextra -Werror
CFLAGS		+=	-iquote $(INC_DIR)
SRC_PATH	=	$(addprefix $(SRC_DIR), $(SRC))
#----unit_test_usefull----#
UT_FLAGS	=	--coverage -lcriterion
UT_PATH		=	$(addprefix $(UT_DIR), $(UT_SRC))
#----general_usefull----#
CC			=	gcc
OBJ			=	$(SRC_PATH:.c=.o)
### COMPILE_USEFULL ###


### RULES_USEFULL ###
RM			=	rm -f
### RULES_USEFULL ###


#------------------------------------------------------------#
.PHONY:		all
all:	$(NAME)
$(NAME):
		$(CC) $(CFLAGS) -o $(NAME) $(SRC_PATH) $(UT_PATH) $(UT_FLAGS)
		mv $(NAME) ../
		../$(NAME) --always-succeed
		mv *.gc* ../
		$(RM) ../$(NAME)

