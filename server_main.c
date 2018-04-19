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
    // File I/O�� �����Ѵ�.(read)
}

void *
thr_write_fn(void *arg)
{
    // File I/O�� �����Ѵ�.(write)
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
         * read�� non-blocking�̱⿡ cpu ���� ���� + while ������
         * �ѹ��� ������ ���� �ƴϱ⿡
         */
        if(read(ti->pipes[0],buffer,sizeof(buffer)) != -1){
            // ������ �͵�...
            printf("22222\n");
        }
    }

    // ������ ����� ���ؼ� �����ش�.
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

// Control Thread�� IO Multiplexing�� �ϸ鼭 request Message output message�� ó��

}

/* Message�� ���� Queue�� ���� ����
 * Queue�� �ϳ��� ����,
 * Worker Thread���� ���������� �о� ���� ���
*/


/* end of server_main.c */
