/**
 * @file    test.c
 * @brief   TODO brief documentation here.
 *
 * @author
 * @version $Id$
 */

/*{{{ Headers ----------------------------------------------------------------*/
#define MAX_EVENTS 5
#define READ_SIZE 10
/*---------------------------------------------------------------- Headers }}}*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>

int OnEvent(const struct epoll_event *event){
    int nread;
    char buf[1024];

    if( event->events & EPOLLIN ){
        nread = read(event->data.fd, buf, 1024);
        if( nread < 1){
            fprintf(stdout, "nread returns : %d\n",  nread);
        } else {
            fprintf(stdout, "data : %s\n", buf);
            buf[0] = 0;
        }
    }
    if( event->events & EPOLLOUT){
    }
    if( event->events & EPOLLERR){
    }
    return 1;
}


int main()
{
    struct epoll_event ev, events[MAX_EVENTS];
    int nfds,n;
    int epoll_fd = epoll_create(10);
    int c_fd[2];

    if(pipe(c_fd) == -1){
        printf("pipe error \n");
        exit(-1);
    }

    if(epoll_fd == -1){
        fprintf(stderr, "Failed to create epoll file descriptor\n");
        exit(-1);
    }

    ev.events = EPOLLIN | EPOLLOUT | EPOLLERR;
    ev.data.fd = c_fd[0];

    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, c_fd[0], &ev)){
        fprintf(stderr, "Failed to add file descriptor to epoll\n");
        close(epoll_fd);
        exit(-1);
    }

    printf("\n Epoll will be start soon...\n");

    for(;;){
        nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, 10);

        if(nfds <0){
            // critical error
            fprintf(stderr, "epoll_wait() error \n");
            break;
        }
        // 아무일도 일어나지 않은경우.
        if(nfds ==0){
            // idle
            continue;
        }

        for(n=0; n<nfds; ++n){
            if(events[n].data.fd == c_fd){
                OnEvent(&events[n]); // pipe 통신 Call_back Function.
            }
//            if(events[n].data.fd == socket_fd) // Socket 통신 Call_back Function.
        }
    }

    return 0;
}
/* end of test.c */
