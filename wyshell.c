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

//
// wyshell.c
// Author: Zachary Crimmel
// Date: Apr 20, 2022
//
// COSC 3750, Homework 8
//
// This is a shell program that was written in c
// Collaborated with Ian Moon on this Homework
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wyscanner.h"

struct word
{
    struct word *next, *prev;
    char *string;
};

typedef struct word Word;

struct node
{
    struct node *node, *prev;
    char *command;
    Word *arg_list;
    int input, output, error;
    char *in_file, *out_file, *err_file;
};

typedef struct node Node;

int rtn = 0;
char *prtn;
char buff[4096];

void addToList(char *input, Node *list)
{
    Word *tmp;
    tmp = list->arg_list;
    if (tmp == NULL)
    {
        tmp = calloc(1, sizeof(Word));
        tmp->string = strdup(input);
        list->arg_list = tmp;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = calloc(1, sizeof(Word));
        tmp->next->prev = tmp;
        tmp->next->string = strdup(input);
    }
    list->arg_list = tmp;
}

int main()
{
    while (1)
    {
        printf("$> ");
        prtn = fgets(buff, 4096, stdin);
        Node *Head, *current = NULL;
        Word *commands = NULL;
        rtn = parse_line(buff);
        current = calloc(1, sizeof(Node));
        int count = 0;
        while (rtn != EOL)
        {
            switch (rtn)
            {
            case WORD:
                if (Head == NULL)
                {
                    Head = calloc(1, sizeof(Node));
                    current = Head;
                    // printf("head created");
                }
                

                if (current->command == NULL)
                {
                    current->command = strdup(lexeme);
                    printf(":--: %s\n", lexeme);
                    // printf("String duplicated");
                }
                else
                {
                    addToList(lexeme, current);
                    printf(" --: %s\n", lexeme);
                    // printf("Command added to list");
                }
                count++;
                // commands = head;
            // case REDIR_OUT:
            //     printf(">\n");
            // }
            }
        }
        commands = calloc(1, sizeof(Word));
        commands = current->arg_list;
        /*while(commands->prev != NULL){
            commands = commands->prev;
        }
        while (commands != NULL)
        {
            printf("%s\n", commands->string);
            commands = commands->next;
        }
        */
    }
}