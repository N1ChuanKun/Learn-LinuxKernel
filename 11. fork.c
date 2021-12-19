#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int a = 0;// 자식 프로세스 수량 감시한 변수

int main()
{
  pid_t pid;//fork() 리턴값이 저장하는 변수
  int i = 10;
  
  printf("PID(%d): parent a = %d, i = %d\n", getpid(), a, i);
  pid = fork();
  
  if(pid < 0)
  {
    printf("fork error!");
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
    wait(NULL);
  }
  
  printf("PID(%d): a = %d, i = %d\n", getpid(), a, i);
  return 0;
}
