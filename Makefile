# 
# Makefile
# Author: Ian Moon
# Date: Apr 19, 2022
#
# COSC 3750, Homework 8
#
# This is a Makefile designed to compile the wyscanner.c/h, 
# simple.c, and wyshell.c
# Collaborated with Zach Chrimmel on this Homework
#

CC=gcc
CFLAGS= -ggdb -Wall
RM= rm -f

.PHONY: new clean tidy

new: wyshell

wyshell: wyscanner.h
	${CC} ${CFLAGS} wyscanner.c wyshell.c -o wyshell

# wyshell.o: wyshell.c
#	${CC} ${CFLAGS} -c wyshell.c

# wyscanner.o: wyscanner.c
#	${CC} ${CFLAGS} -c wyscanner.c

clean:
	${RM} *.o wyscanner

tidy:
	${RM} a.out core.* wyscanner