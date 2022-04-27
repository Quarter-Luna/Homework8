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
  Node *Head = NULL, *current = NULL;
  Word *commands = NULL;
  int flag = 0;
  int overload = 0;
  /******************************
  * Zach tried doing string compare
  * with the &current->prev->command
  * and it was segmentation faulting
  * so I came up with this workaround.
  ********************************/
  while (1)
  {
    printf("$> ");
    prtn = fgets(buff, 4096, stdin);
    if (prtn == NULL)
    {
      printf("\n");
      return 0;
    }
    rtn = parse_line(buff);
    // current = calloc(1, sizeof(Node));
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
        if(overload > 1) 
        {
          printf("Ambiguous output redirection\n");
          rtn = EOL;
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
          current->prev = calloc(1, sizeof(Node));
          // if (strcmp(&current->prev->command, "|") == 0 || strcmp(&current->prev->command, "<") == 0 
          // || strcmp(&current->prev->command, ">") == 0 || strcmp(&current->prev->command, ";") == 0)
          if(flag == 0)
          {
            flag = 1;
            printf(":--: %s\n", lexeme);
          }
          else
          {
            printf("--: %s\n", lexeme);
          }
          // printf("Command added to list");
        }
        count++;
        // commands = head;
        break;
      case REDIR_OUT:
        printf(">\n");
        flag = 0;
        overload++;
        break;
      case REDIR_IN:
        printf("<\n");
        flag = 0;
        overload++;
        break;
      case PIPE:
        printf("|\n");
        flag = 0;
        break;
      case SEMICOLON:
        printf(";\n");
        flag = 0;
        break;
      default:
        break;
      }
      rtn = parse_line(NULL);
    }
    if(overload < 2)
    printf("--: EOL\n");
    /*
        commands = calloc(1, sizeof(Word));
        commands = current->arg_list;
        while(commands != NULL){
            commands = commands->prev;
        }
        while (commands != NULL)
        {
            printf("%s\n", commands->string);
            commands = commands->next;
        }
        */
    current = Head = NULL;
    // current = Head;
    // Node *tmp;
    // while(current) {
    //   free(current->command);
    //   free_words(current->arg_list);
    //   tmp=current;
    //   current=current->next;
    //   free(tmp);
    // }
  }
}
