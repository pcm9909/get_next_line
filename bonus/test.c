#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int     fd[4];
    char    *line;
    int     i;

    fd[0] = open("txt1.txt", O_RDONLY);
    fd[1] = open("txt2.txt", O_RDONLY);
    fd[2] = open("null.txt", O_RDONLY);
    fd[3] = 0;

    i = 0;
    while(fd[i] != 0)
    {
        if(fd[i] == -1)
        {
            printf("Error\n");
            return 1;
        }
        while ((line = get_next_line_bonus(fd[i])))
        {
            printf("%s\n", line);
            free(line);
        }
        close(fd[i]);
        i++;
    }
    return 0;
}