#include <stdio.h>


int main(int ac, char **av, char **env)
{
    char *line;
    size_t n = 0;
    char arr[5];
    getline(&line, &n, stdin);
    printf("%d\n", ac);
    printf("%s", line);
    return (0);
}