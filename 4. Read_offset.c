#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    ssize_t rd;
    char buffer[1024];
    
    fd = open("data.txt", O_RDONLY);
    if(fd == -1)
             printf("error");
             
    rd = pread(fd, buffer, 5, 2); //from fd[2], count 5bits
    
    printf("%s", buffer);
    
    return 0;
}
