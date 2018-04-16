/**
 * @file    linklist_test.c
 * @brief   TODO brief documentation here.
 *
 * @author
 * @version $Id$
 */

/*{{{ Headers ----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*---------------------------------------------------------------- Headers }}}*/

typedef struct Node
{
    int tid;
    int status;
    // 0 idel / 1 working
    struct Node *next; //next link
    struct Node *prev; //prev link
}Node;

Node *head;
Node *tail;
void init(); // init
void add(); // add
void print(); // print
void insert(char *input); // insert
void sch(char *input); // search
void del(); // del
void sort(); // sort
void in(int *tid, int *status); // input data
/*
typedef struct List
{
    Node *head;
    Node *tail;
    int count;
}List;
*/
void init()
{
    head = (Node*) malloc(sizeof(Node)); // 머리동적할당
    tail = (Node*) malloc(sizeof(Node)); // 꼬리동적할당
    head->next = tail;
    head->prev = head;
    tail->prev = head;
    tail->next = tail;
}

//Node 생성은?
void AddData(List *list, int data)
{
    Node *now = NewNode(data);//새로운 노드 생성

    now->prev = list->tail->prev;//now의 prev를 tail 앞 노드로 설정
    now->next = list->tail;//now의 next를 tail로 설정
    list->tail->prev->next = now;//tail의 이전 노드의 next를 now로 설정
    list->tail->prev = now;//tail의 prev를 now로 설정
    list->count++;//보관한 데이터 개수를 1 증가
}


int main(void)
{



/* end of linklist_test.c */
