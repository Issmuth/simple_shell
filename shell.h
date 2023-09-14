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
#include <sys/stat.h>

extern char **environ;

/**
 * struct info - contains info about the shell
 * @name: name of the program
 * @command: command input from the user
 * @args: tokenized arguments of the command
 * @loop_count: counts the number of times
 * the loops has iterated
 * @stat: shell status
 * @mode: interactive vs non-interactive
 */
typedef struct info
{
	char *name;
	char *command;
	char **args;
	int loop_count;
	int stat;
	int mode;
} shell_info;

/**
 * struct builtin - conataint builtins
 * @command: name of buitltin command
 * @func: function that corresponds to it
 */
typedef struct builtin
{
	char *command;
	int (*func)(shell_info __attribute__((unused)) shellf);
}builtin;

/************* STRING TOOLS ************/
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);

/************* TOKEN MAKER*************/
char **tokenize(char *command);

/*********** LOOP ***********/
void looper(shell_info shellf);

/*********** RETRIEVE COMMAND ************/
char *get_command(int *sig);

/********* EXECUTE ***********/
int execute(shell_info shellf);

/********** SIGNAL *********/
void sig_handle(int s);

/********** MEMORY *********/
void freedom(shell_info shellf);

/********* ENVIRONMENT************/
char *_getenv(char *name);

/********** BUILT-INS*************/
int check_builtins(shell_info shellf);
int exit_func(shell_info __attribute__((unused)) shellf);

/*********** PATH ***********/
char **getpath(char *path);
int check_path(shell_info shellf);
void free_mem(char **pathlist);

/********* UTILS ************/
char *_itoa(int n);
void reverse(char *str, int len);
int _atoi(char *str);

/********* ERROR **********/
void print_err(shell_info shellf);
#endif

