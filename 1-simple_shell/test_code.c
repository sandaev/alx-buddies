#include "main.h"

int main(void)
{
    char **args;
    char *line = NULL;
    char *linecpy;
    char *token;
    ssize_t len;
    size_t n = 0;
    char *delim = " \n";
    int i, j, c, len_args;

    len = getline(&line, &n, stdin);
    linecpy = strdup(line);
    token = strtok(line, delim);
    j = 0;
    while (token != NULL)
    {
        j++;
        token = strtok(NULL, delim);
    }
    free(line);
    len_args = j + 1; /* Fixed my headache free(): Invalid pointer */
    args = malloc(sizeof(char *) * len_args);
    if (args == NULL)
    {
        printf("Unable to allocate memory\n");
        exit(0);
    }
    token = strtok(linecpy, delim);
    for (i = 0; token != NULL; i++)
    {
        args[i] = malloc(sizeof(char) * strlen(token));
        if (args[i] == NULL)
        {
            printf("Unable to allocate memory\n");
            exit(0);
        }
        strcpy(args[i], token);
        token = strtok(NULL, delim);
    }
    args[j] = NULL;
    /* Print content of args*/
    for (c = 0; args[c] != NULL; c++)
    {
        printf("%s\n", args[c]);
    }
    /* Free memories allocated */
    for (i = 0; i < c; i++)
    {
        free(args[i]);
    }
    /* Free pointers */
    free(linecpy);
    free(args);
    return(0);
}