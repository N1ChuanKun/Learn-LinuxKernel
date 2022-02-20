//off_t lseek(int fd, off_t pos, int origin); file name, start selection, offset
/*three offset: 1. SEEK_CUR now location
                2. SEEK_END last location
                3. SEEK_SET set location                   */
                

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{   
    int filedes;
    ssize_t nread;
    off_t newpos;
    
    char buffer[1024];
    char content[] = "Hello my friend!!\n";
    
    filedes = open("data.txt", O_RDWR);
    
    nread = read(filedes, buffer, 1024);
    printf("%s", buffer);
    
    newpos = lseek(filedes, 3, SEEK_SET);
    if(newpos == -1)
    {
         printf("error");
    }
    
    nread = read(filedes, buffer, 1024);
    printf("%s", buffer);
    
    close(filedes);
    
    return 0;
}
