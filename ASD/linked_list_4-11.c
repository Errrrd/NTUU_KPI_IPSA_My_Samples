//4 – 11. Для однозв’язного списку типу час (поля: hour, minute) реалізувати
//функції:
//а) додавання елемента у голову списку;
//б) видалення елемента з голови списку;
//в) поміняти місцями найбільший та найменший елементи;
//г) надрукувати весь список, формат: “h: hour, m: minute”;
//д) видалити весь список.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16
#define RAND_H() rand()%(24)
#define RAND_M() rand()%(60)

typedef struct linkedListNode {
    int hour;
    int minute;
    struct linkedListNode * next;
} node;

node * createNode(int hour, int minute);
node * createNodeGen();
void addToTail(node** headAddr, node* newTail);
void addToHead(node** headAddr, node* newHead); //а) додавання елемента у голову списку;
void remFromHead(node** headAddr); //б) видалення елемента з голови списку;
void switchMinAndMax(node** headAddr); //в) поміняти місцями найбільший та найменший елементи;
void printList (node * head); //г) надрукувати весь список, формат: “h: hour, m: minute”;
void freeList(node** headAddr ); //д) видалити весь список.

int main(){
    int hour;
    int minute;
    node * head = NULL;
    srand( time(NULL) ); // using rand from current time
    
    for (int i = 0; i < SIZE; i++){
        hour = RAND_H();
        minute = RAND_M();
        //printf("h:%d, m:%d\n", hour, minute);
        addToTail(&head, createNode(hour, minute));
    }
    printList(head);
    
    printf("Add new element to Head\n");
    addToHead(&head, createNodeGen());
    printList(head);
    
    printf("switch Min and Max element\n");
    switchMinAndMax(&head);
    printList(head);
    
    printf("Remove element from Head\n");
    remFromHead(&head);
    printList(head);
    
    freeList(&head);
    assert(head == NULL);
    
    return 0;
}

node * createNode(int hour, int minute)
{
    node * newNode = (node *) malloc (sizeof(node));
    assert(newNode != NULL);
    
    newNode->next = NULL;
    newNode->hour = hour;
    newNode->minute = minute;
    
    return newNode;
}

node * createNodeGen()
{
    node * newNode = (node *) malloc (sizeof(node));
    assert(newNode != NULL);
    
    newNode->next = NULL;
    newNode->hour = RAND_H();
    newNode->minute = RAND_M();
    
    return newNode;
}


void addToTail(node** headAddr, node* newTail)
{
    if (newTail == NULL){
        printf("New element is empty/wrong");
        exit(1);
    }
    if (*headAddr == NULL ){
        *headAddr = newTail;
    } else {
        node * oldTail = *headAddr;
        while(oldTail->next != NULL) oldTail = oldTail->next; 
        oldTail->next = newTail;
    }
}

void addToHead(node** headAddr, node* newHead)
{
    if (newHead == NULL){
        printf("New element for head is empty/wrong");
        exit(1);
    }
    if (*headAddr == NULL ){
        *headAddr = newHead;
    } else {
        newHead->next = *headAddr;
        *headAddr = newHead;
    }
}

void remFromHead(node** headAddr)
{
    node * oldHead = *headAddr;
    *headAddr = oldHead->next;
    free(oldHead);
}

void switchMinAndMax(node** headAddr)
{
    node * tmp = *headAddr;
    node * max = *headAddr;
    node * min = *headAddr;
    node * preMax = NULL;
    node * preMin = NULL;
    node * nextMax = NULL;
    node * nextMin = NULL;
    
    while (tmp !=NULL){
        if(tmp->next != NULL){
            if ( (max->hour < tmp->next->hour) ||
                 (max->hour == tmp->next->hour &&
                  max->minute < tmp->next->minute) )
            {
                max = tmp->next;
                preMax = tmp;
                nextMax = max->next;
            }
            if ( (min->hour > tmp->next->hour) ||
                 (min->hour == tmp->next->hour &&
                  min->minute > tmp->next->minute) )
            {
                 min = tmp->next;
                 preMin = tmp;
                 nextMin = min->next;
            }
        }
        tmp = tmp->next;
    }
    printf("max[h:%2d, m:%2d]\n", max->hour, max->minute);
    printf("min[h:%2d, m:%2d]\n", min->hour, min->minute);
    if (max != min){
        if (preMax != NULL) preMax->next = min;
        if (preMin != NULL) preMin->next = max;
        max->next = nextMin;
        min->next = nextMax;
    }
}
void printList (node * head){
    printf("\n---------- Linked List ----------\n[ ");
    if(head == NULL){
        printf("is empty\n");
    } else {
        
        while(head->next != NULL){
            printf("{h:%2d, m:%2d} -> ", head->hour, head->minute);
            head = head->next;
        }
    }
    printf("{h:%d, m:%d} ]\n---------- Linked List ----------\n", head->hour, head->minute);
}

void freeList(node** headAddr ){
    node * temp;
    while (*headAddr !=NULL){
        temp = (*headAddr)->next;
        free(*headAddr);
        *headAddr = temp;
    }
    *headAddr = NULL;
}
