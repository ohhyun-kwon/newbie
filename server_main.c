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
    // File I/O�� �����Ѵ�.
}


int main(void)
{
    int err;

    printf("Program will start soon!!!\n");
// Control Thread�� IO Multiplexing�� �ϸ鼭 request Message output message�� ó��


    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err !=0)
        printf("Cannot Create thread!!\n");



}

/* Message�� ���� Queue�� ���� ����
 * Queue�� �ϳ��� ����,
 * Worker Thread���� ���������� �о� ���� ���
*/


/* end of server_main.c */
