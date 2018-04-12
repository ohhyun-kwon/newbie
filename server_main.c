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
/*---------------------------------------------------------------- Headers }}}*/

#define MAX_PTHREAD 100
#define CREATE_PTHREAD 3

struct thread_pool
{
    int tid;
    int status;
    // 0 idle / 1 working
    int tid_a[CREATE_PTHREAD];
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
thr_wait(struct thread_pool *tp)
{
    static int i=0;

    tp->tid = pthread_self();
    tp->status = 0;
    tp->tid_a[i]=tp->tid;
    printf("%d��° %d tid %d\n",i,tp->tid,tp->status);
    ++i;
    sleep(1);
}

int main(void)
{
    printf("Program will start soon!!!\n");
    // Thread pool
    int i;
    int err;
    struct thread_pool tp;
    pthread_t ntid;

    if(CREATE_PTHREAD<MAX_PTHREAD)
        for(i=0; i<CREATE_PTHREAD; i++)
        {
            err = pthread_create(&ntid, NULL, thr_wait, &tp);
            if (err !=0)
                printf("Cannot Create thread!!\n");
            sleep(1);

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
