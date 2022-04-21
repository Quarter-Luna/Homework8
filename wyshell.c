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

#include "wyscanner.h"
#include <stdio.h>

int main()
{
    char args[4096];
    while (1)
    {
        printf("$> ");
        fgets(args, 4096, stdin);
    
    }
}