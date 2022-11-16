#include "main.h"
/**
* 
*
*/
 char *read_line(void)
{
    char *line;
    size_t n = 0;
    size_t num_line;

    getline(&line, &n, stdin); //welcome world
    return (line);
}
char **split_line(char *line)
{
    char **tokens = NULL;
    char *line_copy;
    char *token = NULL;
    char *tok;
    int num_toks = 0;
    int i;
    char *delim = " \t\r\n";

    line_copy = strdup(line);
    /* Get length of tokens */
    tok = strtok(line, delim);
    while (tok != NULL)
    {
        num_toks++;
        tok = strtok(NULL, delim);
    }
    num_toks++;
    /* Allocate memory to hold number (num_toks) of tokens */
    tokens = malloc(sizeof(char*) * num_toks);
    if (tokens == NULL)
    {
        printf("Error allocating memory.");
        exit(-1);
    }
    /* Add each token to the array tokens */
    tok = strtok(line_copy, delim);
    for (i = 0; tok != NULL; i++)
    {
        token = malloc(sizeof(char) * strlen(tok));
        if (token == NULL)
        {
            printf("token: Error allocating memory.\n");
            exit(-1);
        }
        strcpy(token, tok);
        tokens[i] = token;
        tok = strtok(NULL, delim);
    }
    tokens[i] = NULL;
    return (tokens);
}
/* execute command */
void execute(char **args)
{
    pid_t child_pid = fork();
    int stat;
    //extern char *environ;

    if (child_pid == 0)
    {
        if (args[0] != NULL)
        {
            //execvp(args[0], args);
            execve(args[0], args, NULL);
            perror("cisfun");
            exit(1);

        }
    }
    else if (child_pid > 0)
    {
        do
        {
            waitpid(child_pid, &stat, WUNTRACED);
        } while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
    }
    else
    {
        perror("cisfun");
    }
}