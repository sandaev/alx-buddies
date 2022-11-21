#include "main.h"
/**
 * validate_input - Validates user input
 * 
 * Return: Pointer to string
*/
char *validate_input()
{
    char *line;
    size_t buffer;
    ssize_t len_line;

    len_line = getline(&line, &buffer, stdin);
    if (*line == ' ' || *line == '\n')
    {
        return (NULL);
    }
    if (len_line == -1)
    {
        *line = '-';
    }
    return (line);
}
char **command_args(char *line)
{
    char **args;
    char *linecpy;
    int len, i;
    (void) linecpy;

    /* Get the length of input*/
    len = strlen(line);
    /* Allocate memory for NULL terminated array of command(s)*/
    args = malloc(sizeof(char *) * 2);
    if (args == NULL)
    {
        perror("./swsh");
        printf("args is null\n");
        exit(0);
    }
    args[0] = malloc(sizeof(char) * len);
    /* Copy command into array */
    for (i = 0; line[i] != '\n'; i++)
    {
        args[0][i] = line[i];
    }
    args[0][i] = '\0';
    args[1] = NULL;
    return (args);
}
void freeMem(char **args)
{
    int i;

    for (i = 0; args[i] != NULL; i++)
    {
        free(args[i]);
    }
    free(args);
}
/* Executes command*/
/*void execute(char **args)
{
    pid_t child_pid = fork();
    extern char **environ;
    int wstatus;

    execve(args[0], args, environ);

    if (child_pid == 0)
    {
        printf("in child b4 execve: %s\n", args[0]);
        if (args[0] != NULL)
        {
            if(execve(args[0], args, environ) < 0)
            {
                printf("After execve: %s\n", args[0]);
                perror("./swsh");
                exit(0);

            }
        }
        printf("Invalid pointer: args\n");
        exit(0);
    }
    else if (child_pid > 0)
    {
        waitpid(child_pid, &wstatus, WUNTRACED);
        do
        {
            waitpid(child_pid, &wstatus, WUNTRACED);
        } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
        printf("Parent %ul\n", child_pid);
    }
    else
    {
        waitpid(child_pid, &wstatus, WUNTRACED);
        printf("PArent: %ul", child_pid);
        perror("./swsh");
    }
}*/