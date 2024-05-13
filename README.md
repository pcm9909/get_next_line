Compile ( Make your own main file ) 
```c
cc get_next_line.c get_next_line_utils.c [your main file]
```

Example for editing main.c
```c
int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY); // Insert your textfile name ended by .txt
    if (fd == -1)
    {
        printf("file open fail");
        return (1);
    }
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
