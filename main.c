#include "main.h"

int main(void)
{
    char *prompt = "cisfun$ ";
    char *line;
    char **tokens = NULL;
    size_t n = 0;
    ssize_t num_line;
    int i;
    int status = 1;

    while (status)
    {
        printf("%s", prompt);
        line = read_line();
        tokens = split_line(line);
        execute(tokens);
    }
    free(line);
    free(tokens);
    return (0);
}