#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5      /* During this time if not data return, selete() get 0 and safe NULL. */
#define BUF_LEN 1024

int main(void)
{
    struct timeval tv;
    fd_set readfds;
    int ret;
    
    FD_ZERO(&readfds); //initialize
    FD_SET(STDIN_FILENO, &readfds); 
    /*
    FD_SET: 주어진 집합에 파일디스크립터를 추가한다
    FD_ISSET: 파일디스크립터가 집합에 존재하는지 검사한다. 있으면 0이 아닌 정수 반환한다.
    FD_ZERO: 집합을 초기화, select() system call 호출하기전에 사용한다.
    */
    
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    
    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);
    
    if(ret == -1){
       perror("select");
       return 1;
    }
    else if (!ret){
       printf("%d seconds elapsed.\n", TIMEOUT);
       return 0;
    }
    
    if(FD_ISSET(STDIN_FILENO, &readfds)){
       char buf[BUF_LEN];
       int len;
       
       len = read(STDIN_FILENO, buf, BUF_LEN);
       if(len == -1) return 1;
       if(len){
          buf[len] = '\0';
          printf("read: %s\n",buf);
       }
       
       return 0;
   }
}
