##
## EPITECH PROJECT, 2019
## Dante
## File description:
## Root Makefile
##

#------------------------------------------------------------#
.PHONY:		all
all:
			make -C generator/ all
			make -C solver/ all

#------------------------------------------------------------#
.PHONY:		tests_run
tests_run:

#------------------------------------------------------------#
.PHONY:		clean
clean:
			make -C generator/ clean
			make -C solver/ clean
			$(RM) *.gc*

#------------------------------------------------------------#
.PHONY:		fclean
fclean:		clean
			make -C generator/ fclean
			make -C solver/ fclean
			$(RM) $(UT_NAME)

#------------------------------------------------------------#
.PHONY:		re
re:			fclean all
