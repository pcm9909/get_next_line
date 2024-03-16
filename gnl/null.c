#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(void)
{
    int fd;
    char *line;

    fd = open("null.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("file open fail");
        return (1);
    }
    while ((line = get_next_line(fd)))
        printf("%s\n", line);
    close(fd);
    return (0);
}
