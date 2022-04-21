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
    Node *Head, *current;

    char args[1024];
    char *argl;
    int com;
    int in, out, err; // STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO
    char* infile, outfile, errfile;
    while (1)
    {
        printf("$> ");
        Head = current = NULL;
        argl = fgets(args,256,stdin);
        com = parse_line(args);
        while(com != EOL) 
        {
            switch(com) 
            {
                case WORD:
                  if(Head==NULL)
                  {
                    Head = newNode();
                    current = Head;
                  }
                  if(current->command==NULL) 
                  {
                    current->command=strdup(lexeme);
                  }
                  else
                  {
                    wordAdd(Head,current);
                  }
                  break;
                  case REDIR_OUT:
                    
            }
        }
    }
}