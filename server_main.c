/**
 * @file    server_main.c
 * @brief   TODO brief documentation here.
 *
 * @author
 * @version $Id$
 */

/*{{{ Headers ----------------------------------------------------------------*/
#include <stdio.h>
#include "apue.h"
#include <pthread.h>
#include <unistd.h>
/*---------------------------------------------------------------- Headers }}}*/

#define MAX_PTHREAD 100
#define CREATE_PTHREAD 5


typedef struct thread_info thread_info;
struct thread_info
{
    int tid;
    // 0 idle : 1 working
    int status;
    int pipes[2];
};

typedef struct thread_pool thread_pool;
struct thread_pool
{
    thread_info ti[CREATE_PTHREAD];

};

/*
void *
thr_read_fn(void *arg)
{
    // File I/O를 수행한다.(read)
}

void *
thr_write_fn(void *arg)
{
    // File I/O를 수행한다.(write)
}
*/

void *
thr_init_wait(void *tpp)
{
    thread_info *ti = (thread_info *)tpp;
    char buffer[256];

    // init
    ti->tid = pthread_self();
    ti->status = 0;
    pipe(ti->pipes);

    printf("tid %d status %d %d pipes\n",
           ti->tid, ti->status,
           ti->pipes[0], ti->pipes[1]);

    // wait
    while(1){
        printf("11111\n");
        /*
         * read는 non-blocking이기에 cpu 걱정 ㄴㄴ + while 쓴것은
         * 한번만 수행할 것이 아니기에
         */
        if(read(ti->pipes[0],buffer,sizeof(buffer)) != -1){
            // 수행할 것들...
            printf("22222\n");
        }
    }

    // 수행한 결과에 대해서 보내준다.
}
/*
void thr_get()
{

}
*/
int main(void)
{
    printf("Program will start soon!!!\n");
    // Thread pool
    int i;
    int err;
    thread_pool tp;
    thread_info ti;
    pthread_t ntid;

    if(CREATE_PTHREAD<MAX_PTHREAD){
        for(i=0; i<CREATE_PTHREAD; i++)
        {
            printf("%d thread\n", i);
            err = pthread_create(&ntid, NULL, thr_init_wait, &(tp.ti[i]));
            if (err !=0)
                printf("Cannot Create thread!!\n");
            sleep(1);

        }
    }
    else
        printf("Too much for thread pool!!\n");

// Control Thread는 IO Multiplexing을 하면서 request Message output message를 처리

}

/* Message를 담을 Queue를 직접 구현
 * Queue는 하나만 생성,
 * Worker Thread들이 경쟁적으로 읽어 가는 방식
*/


/* end of server_main.c */
