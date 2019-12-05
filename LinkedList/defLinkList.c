#include "node.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct node{
//  int value;
//  struct node* next;
//} Node;

typedef struct _pNode{
  Node *head;
  Node *tail;
} List;

void add(List *head, int number);

int main(int argc, char const *argv[])
{
  List list;
  int number;
  list.head = NULL;

  do{
    scanf("%d", &number);
    if (number!= -1){
      add(&list, number);
    }
  }while(number!=-1);

  return 0;
}

//函数add的形参是类型为List的指针;而Node* list则是类型为Node的指针。两者成员不同
void add(List *list, int number){  
  Node *p = (Node*)malloc(sizeof(Node));
  p->value = number;
  p->next = NULL;
  Node* last = list->head;
  if(last){
    while(last->next){
      last = last->next;
    }
    last->next = p;
  }else{
    list->head = p;
  }
}
