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

void *
thr_fn(void *arg)
{
    // File I/O를 수행한다.
}


int main(void)
{
    int err;

    printf("Program will start soon!!!\n");
// Control Thread는 IO Multiplexing을 하면서 request Message output message를 처리


    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err !=0)
        printf("Cannot Create thread!!\n");



}

/* Message를 담을 Queue를 직접 구현
 * Queue는 하나만 생성,
 * Worker Thread들이 경쟁적으로 읽어 가는 방식
*/


/* end of server_main.c */
