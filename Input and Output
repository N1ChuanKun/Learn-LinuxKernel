#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int fd;
    ssize_t nread;
    
    char buffer[1024];
    char content[] = "hello world\n";
    
    fd = open("data.txt", O_RDWR);
    
    nread = read(fd, buffer, 1024);
    printf("%s", buffer);
    
    write(fd, content, strlen(content));
    
    close(fd);
    
    return 0;
}
