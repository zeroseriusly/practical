#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    char *args[] = {"./allpro", NULL};
    execvp(args[0], args);
    printf("End\n");
    return 0;
}