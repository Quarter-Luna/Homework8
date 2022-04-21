/*************************************
 * wyshell.c
 * Author: Ian Moon
 * Date: 19 April 2022
 *
 * This file is the set up the shell
 * using functions from the wyscanner
 * to make a working shell
 * 
 * Collaborated with Zach Chrimmel on 
 * this project
 ************************************/

#include "wyscanner.c"
#include <stdio.h>

int main() 
{
    char args;
    while(1)
    {
        printf("$> ");
        parse_line(stdin);
        
    }
}