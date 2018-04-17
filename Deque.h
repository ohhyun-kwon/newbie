/**
 * @file    Deque.h
 * @brief   TODO brief documentation here.
 *
 * @author
 * @version $Id$
 */

#ifndef _DEQUE_H
#define _DEQUE_H

/*{{{ Headers ----------------------------------------------------------------*/
/*---------------------------------------------------------------- Headers }}}*/

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
}Node;

typedef struct _dlDeque
{
    Node *head;
    Node *tail;
}DlDeque;

typedef DlDeque Deque;

void DequeInit(Deque *pdeq);
int DQIsEmpty(Deque *pdeq);

void DQAddFist(Deque *pdeq, Data data); // Add data into head
void DQAddLast(Deque *pdeq, Data data); // Add data into tail

Data DQRemoveFist(Deque *pdeq); // remove data from head
Data DQRemoveLast(Deque *pdeq); // remove data from tail

Data DQGetFirst(Deque *pdeq); // reference data from head
Data DQGetLast(Deque *pdeq); // reference data from tail


#endif /* no _DEQUE_H */
