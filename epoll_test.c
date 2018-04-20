/**
 * @file    test.c
 * @brief   TODO brief documentation here.
 *
 * @author
 * @version $Id$
 */

/*{{{ Headers ----------------------------------------------------------------*/
/*---------------------------------------------------------------- Headers }}}*/
#include <stdio.h>     // for fprintf()
#include <unistd.h>    // for close()
#include <sys/epoll.h> // for epoll_create1()

int main()
{
    int epoll_fd[2];
    int i;

    for(i=0;i<2;i++)
    {
        epoll_fd[i] = epoll_create(1);
        printf("%d\n",epoll_fd[i]);

        if(epoll_fd[i] == -1)
        {
            fprintf(stderr, "Failed to create epoll file descriptor\n");
            return 1;
        }

    }

    return 0;
}



/* end of test.c */
