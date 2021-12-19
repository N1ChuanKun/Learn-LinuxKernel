#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>

int main()
{
  char love[12] = {0}, hello[13] = {0}, test[13] = {0};
  struct iovec iov[3];
  ssize_t nr;
  int fd, i;
  
  fd = open("vectest.txt", O_RDONLY);
  if(fd < 0)
  {
    perror("error");
    return -1;
  }
  
  iov[0].iov_base = love;
  iov[0].iov_len = sizeof(love) - 1;
  iov[1].iov_base = hello;
  iov[1].iov_len = sizeof(hello) - 1;
  iov[2].iov_base = test;
  iov[2].iov_len = sizeof(test) - 1;
  
  nr = readv(fd, iov, 3);
  
  printf("read: %ld bytes.\n", nr);
  printf("%s\n", love);
  pirntf("%s\n", hello);
  printf("%s\n", test);
  
  return 0;
}
