#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int a = 0;//자식 프로세스 수량 감시한 변수

int main()
{
  pid_t pid;
  int i = 10;
  
  printf("PID(%d): parent a = %d, i = %d\n", getpid(), a, i);
  
  pid = vfork();
  
  if(pid < 0)
  {
    printf("vfork error");
    exit(1);
  }
  else if(pid == 0)
  {
    a++;
    i++;
    printf("PID(%d): Child a = %d, i = %d\n", getpid(), a, i);
  }
  else
  {
    printf("PID(%d): parent a = %d, i = %d\n", getpid(), a, i);
  }
  
  printf("PID(%d): parent a = %d, i = %d\n", getpid(), a, i);
  return 0;
}

/*
reult:
PID(): parent a = 0, i = 10
PID(): Child a = 1, i = 11
PID(): parent a = 1, i = 11
PID(): a = 1, i = 11
*/
