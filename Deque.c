/**
 * @file    Deque.c
 * @brief   TODO brief documentation here.
 *
 * @author
 * @version $Id$
 */

/*{{{ Headers ----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "Deque.h" /*SELF*/
/*---------------------------------------------------------------- Headers }}}*/

void DequeInit(Deque *pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
    if(pdeq->head == NULL) // head가 Null일 경우 비어있는 Deque
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;

    if(DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;

    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pdeq->tail;

    if(DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
    Node *rnode = pdeq->head;
    Data rdata;

    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!\n");
        exit(-1);
    }
    rdata = pdeq->head->data;

    pdeq->head = pdeq->head->next;
    free(rnode);

    if(pdeq->head == NULL)
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;

    return rdata;
}

Data DQRemoveLast(Deque *pdeq)
{
    Node *rnode = pdeq->tail;
    Data rdata;

    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!\n");
        exit(-1);
    }
    rdata = pdeq->tail->data;

    pdeq->tail = pdeq->tail->prev;
    free(rnode);

    if(pdeq->tail ==NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;

    return rdata;
}

Data DQGetFirst(Deque *pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    return pdeq->head->data;
}

Data DQGetLast(Deque *pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    return pdeq->tail->data;
}

int main(void)
{
    // Deque create
    Deque deq;
    DequeInit(&deq);

    DQAddFirst(&deq,3);
    DQAddFirst(&deq,2);
    DQAddFirst(&deq,1);

    DQAddLast(&deq,4);
    DQAddLast(&deq,5);
    DQAddLast(&deq,6);

    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveFirst(&deq));

    printf("\n");

    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq,4);
    DQAddLast(&deq,5);
    DQAddLast(&deq,6);

    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveLast(&deq));

    return 0;
}

/* end of Deque.c */
