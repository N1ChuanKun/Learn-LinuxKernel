#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
  pid_t pid;
  int count = 0;
  
  pid = fork();
  
  if(pid < 0)
    perror("error in fork");
  else if(pid == 0){
    printf("Child, ID: %d\n", getpid());
    count++;
  }
  else {
    printf("Father, ID: %d\n", getpid());
    count++;
  }
  printf("Total: %d", count);
  return 0;
}
