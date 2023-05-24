#ifndef SEHLL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>


int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int size_t, unsigned int n_size);

char **splitstring(char *str, const char *delim);
void execute(char **argv);

void sig_handler(int sig);
void _EOF(int read_char, char *buffer);
void _isatty(void);
int main(int arc, char **argv);

extern char **environ;
char *_getenv(const char *name);

#endif
