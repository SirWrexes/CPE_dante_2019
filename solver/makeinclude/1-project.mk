##
## EPITECH PROJECT, 2019
## Multipart Makefile
## File description:
## Project/binary name and sources
##

#
# Project and binary name
################################################
NAME := Dante\'s Star (solver)
BIN  := solver
################################################

#
# Libs to include
################################################
LIBS +=
################################################

#
# Custom CFLAGS
################################################
CUSTOM_CFLAGS := -D__USE_GNU
################################################

#
# Sources
################################################
MAIN := ./src/main.c
# -------------------------------------------- #
SRC := ./bonus/maze_pretty_print.c
SRC += ./src/astack.c
SRC += ./src/astar_neighbours.c
SRC += ./src/astar_search.c
SRC += ./src/maze_make_matrix.c
################################################

#
# Test sources
################################################
TST :=
TST +=
################################################


#
# Files created by unit tests functions
################################################
TESTTMP := *.tmp
TESTTMP +=
################################################
