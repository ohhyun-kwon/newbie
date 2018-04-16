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
    head = (Node*) malloc(sizeof(Node)); // �Ӹ������Ҵ�
    tail = (Node*) malloc(sizeof(Node)); // ���������Ҵ�
    head->next = tail;
    head->prev = head;
    tail->prev = head;
    tail->next = tail;
}

//Node ������?
void AddData(List *list, int data)
{
    Node *now = NewNode(data);//���ο� ��� ����

    now->prev = list->tail->prev;//now�� prev�� tail �� ���� ����
    now->next = list->tail;//now�� next�� tail�� ����
    list->tail->prev->next = now;//tail�� ���� ����� next�� now�� ����
    list->tail->prev = now;//tail�� prev�� now�� ����
    list->count++;//������ ������ ������ 1 ����
}


int main(void)
{



/* end of linklist_test.c */
