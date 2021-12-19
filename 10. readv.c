#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>

int main()
{
  char love[12] = {0}, hello[13] = {0}, test[13] = 0;
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
  iov[0].iov_len = sizeof(love);
  iov[1].iov_base = hello;
  iov[1].iov_len = sizeof(hello);
  iov[2].iov_base = test;
  iov[2].iov_len = sizeof(test);
  
  nr = readv(fd, iov, 3);
  
  printf("read %ld bytes.\n", nr);
  for(i = 0; i < 3; i++)
  {
    printf("%d: %s\n", i, (char*)iov[i].iov_base);
  }
  
  return 0;
}
