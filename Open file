//open() system call
//1. int open(const char *name, int flag);              //file name, mode
//2. int open(const char *name, int flags, mode_t_mode) //file name, mode, 권한

#include <sys/types.h>
#include <sys.stat.h>
#include <fcntl.h>

int main(void)
{
    int fd; //file name
    fd = open("file1.txt", O_CREAT | O_WRONLY | O_TRUNC); //open file1.txt with creat mode + write only mode + trunc mode
    if(fd == -1)
         //Error!
}
