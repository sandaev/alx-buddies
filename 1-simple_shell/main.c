#include "main.h"
/**
 * main - Entry point of the program
 * 
 * Return: Always 0
*/
int main(int ac, char **av, char **env)
{
    char *prompt = "swsh$ ";
    char *line;
    char **args;
    int wstatus;
    size_t buffer;
    ssize_t len_line;
    (void) ac;
    (void) av;

    while (1)
    {
        printf("%s", prompt);
        /*line = validate_input();*/
        len_line = getline(&line, &buffer, stdin);
        if (line == NULL || *line == '\n')
        {
            continue;
        }
        if (len_line == -1)
        {
            printf("\n");
            exit(0);
        }
        printf("%ld\n", len_line);
        args = command_args(line);
        if (fork() == 0)
        {
            execve(args[0], args, env);
            perror("./swsh");
            exit(0);
        }
        else
        {
            wait(&wstatus);
        }
        free(line);
        freeMem(args);      
    }
    return (0);
}