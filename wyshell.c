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

typedef struct node Node;
typedef struct word Word;

struct node
{
    struct node *next, *prev;
    char *command;
    Word *arg_list;
    int input, output, error;
    char *in_file, *out_file, *err_file;
};

struct word
{
    struct word *next, *prev;
    char *string;
};

void wordAdd(Node *node, const char* arg) 
{
    
}

int main()
{
    Node *Head = NULL, *current = NULL;

    char args[4096];
    while (1)
    {
        if (Head == NULL)
        {
            Head = calloc(1,sizeof(Node));
            current = Head;
            printf("$> ");
            fgets(args, 4096, stdin);

        }
    }
}