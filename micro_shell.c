#include <stdio.h>
#define PIPE 1
#define ARG 0
#define PVRG 2
int main(int ac, char **av)
{
    int i = -1;
    int tokens[ac];
    while (av[++i])
    {
        if (strncmp(av[i], "\";\"", 3) == 0)
            tokens[i] = PVRG;
        else if (strncmp(av[i], "\"|\"", 3) == 0)
            tokens[i] = PIPE;
        else
            tokens[i] = ARG;
    }

    i = -1;
    while ()
}