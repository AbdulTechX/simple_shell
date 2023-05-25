#ifndef SEHLL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int size_t, unsigned int n_size);
char *concat_all(char *str1, char *str2, char *str3);

char **splitstring(char *str, const char *delim);
void execute(char **argv);

void sig_handler(int sig);
void _EOF(int read_char, char *buffer);
void _isatty(void);
int main(void);

extern char **environ;
char *_getenv(const char *name);


void env(char **argv __attribute__ ((unused)));


/**
 * struct list_path - Linked list containing PATH directories
 * @next: directory in path
 * @ptr: pointer to next node
 */
typedef struct list_t
{
	char *next;
	struct list_t *ptr;
} list_t;


char *_which(char *filename, list_t *head);
list_t *add_node_end(list_t **head, char *str);
list_t *path_fill(char *path);



/**
 * struct mybuiltin - pointer to function with corresponding buildin command
 * @path: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuiltin
{
	char *path;
	void (*func)(char **);
} mybuiltin;


int _atoi(char *s);
void exitt(char **argv);


void (*check_builtin(char **cmd))(char **cmd);

/* free memory */
void free_prompt(char **prompt);
void free_list(list_t *head);


#endif
