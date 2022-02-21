#include<stdio.h>
#include<unistd.h>
#define MAX 2

int main() {
	int i, status, pid;
	for (i = 0; i < MAX; i++) {
		status = fork();
		if (status == 0 || status == -1) { 
			break; 
			//如果是子进程就跳出来，保证只有父进程创建子进程
		}
		if (status == -1) {
			printf("ERROR!\n");
		}
		else if (status == 0) {
			if (i == 0)printf("B");//第一个子进程，输出B
			else if (i == 1)printf("C");//第二个子进程，输出C
			wait(NULL);
		}
		else {
			printf("A");
      //下面题目没有要求是可以不要
			while ((pid = wait(&status) > 0)) {
				printf("son id:%d is done\n", pid);
			}
		}
	}
  return 0;
}
