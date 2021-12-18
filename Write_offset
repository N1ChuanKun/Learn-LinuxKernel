#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    ssize_t rd;
    char buffer[1024] = "hello world\n";
    
    fd = open("data.txt", O_WRONLY);
    if(fd == -1)
            printf("error");
            
    rd = pwrite(fd, buffer, 7 , 0); // from fd[0] write 7bits
    
    return 0;
}
