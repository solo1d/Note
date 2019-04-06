/*
	多线程基本规范
	当使用 gcc 编译的时候,必须是这种格式   gcc c.c -lpthread   
	后面的 -o  改名参数 可有可无
 锁会非常影响效率
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 500000000

typedef struct{
    int first;
    int last;
    int id;
}MY_ARGS;

int* arr;
int results[101];

void* myfunc(void* args){
    int i ;
    MY_ARGS* my_args = (MY_ARGS*) args;
    int first = my_args->first;
    int last  = my_args->last;
    int id    = (my_args->id) * 100;
    
    for(i=first; i<last ; ++i){
        results[id] = results[id] + arr[i];
    }
}


int main(void){

    int i ;
    arr = malloc(sizeof(int)*MAX_SIZE);
    for(i=0; i<MAX_SIZE; ++i){
        arr[i] = rand() % 5;
    }
    results[0] = 0;
    results[100] = 0;
    
  
	pthread_t th1;
    pthread_t th2;
    
    int mid = MAX_SIZE/2;
    MY_ARGS args1 = {0,  mid, 0};
    MY_ARGS args2 = {mid,MAX_SIZE, 1};
    
    pthread_create(&th1,NULL, myfunc, &args1);
    pthread_create(&th2,NULL, myfunc, &args2);
    
    pthread_join(th1,NULL);      // 等待th1 运行结束
    pthread_join(th2,NULL);      // 等待th2 运行结束

    printf("s1 = %d\n",results[0]);
    printf("s2 = %d\n",results[100]);
    printf("s1 + s2 = %d\n",results[0] + results[100]);
	return 0;
}
