#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 1024

int shell_setenv(const char *name, const char *value);
void call_and_execute(char *args[], char *valget);
int shell_unsetenv(const char *name);
int shell_cd(const char *directory);
void execute_builtin_command(char **command, char *valget);
char *ogo_getline(void);
char *ogo_strtok(char *str, const char *delim);
char *ogo_non_interactive_getline(void);
char *ogo_getenv(char *enviro);
int _putchar(char c);
size_t _strlen(const char *str);
int _printf(const char *format, ...);
void print_integer(int val);
int err_putchar(char c);
int _integer_length(int integer);
int _fprintf(FILE *stream, const char *format, ...);
int _strcmp(char *s1, char *s2);
int ogo_strncmp(char *str1, char *str2, int num);

extern char **environ;
#endif

