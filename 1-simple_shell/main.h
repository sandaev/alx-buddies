#ifndef MAINH
#define MAINH

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
char *read_line(void);
char **split_line(char *);
/*void execute(char **args);*/
char *validate_input();
char **command_args(char *line);
void execute(char **);
void freeMem(char **);

#endif /* ifndef MAINH */
