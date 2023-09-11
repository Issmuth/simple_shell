#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;

/**
 * struct info - contains info about the shell
 * @command: command input from the user
 * @args: tokenized arguments of the command
 * @loop_count: counts the number of times
 * the loops has iterated
 * @stat: shell status
 */
typedef struct info
{
	char *command;
	char **args;
	int loop_count;
	int stat;
	pid_t pid;
} shell_info;

/************* STRING TOOLS ************/
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_strcat(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);

/************* TOKEN MAKER*************/
int count_whitespace(char *command);
char **tokenize(char *command);

/*********** LOOP ***********/
void looper(shell_info *shellf);

/*********** RETRIEVE COMMAND ************/
char *get_command(int *sig);

/********* EXECUTE ***********/
void execute(shell_info *shellf);

/********** SIGNAL *********/
void sig_handle(int s);

/********** MEMORY *********/
void freedom(shell_info *shellf);

#endif

