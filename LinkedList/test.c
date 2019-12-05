#include "node.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct node{
////  int value;
////  struct node* next;
////} Node;

//time 11:22

typedef struct list_node{
  Node* head;
  Node* tail;
} List;

int Length(List* plist);
void add(List* plist, int number);
void print(List* plist);
void delete(List* plist, int n);

int main(int argc, char const *argv[]){
  int number;
  //下面这两行忘记写上了
  List list;
  list.head=NULL;
  do{
    if(number!=-1){
      scanf("%d", &number);
      add(&list, number);
    }
  }while(number!=-1);
  
  int l=0;
  print(&list);
  l = Length(&list);
  printf("Length of LinkList is: %d\n", l);
  printf("Delete which number: ");
  int n;
  scanf("%d", &n);
  delete(&list, n);
  print(&list);
  l = Length(&list);
  printf("Now length of LinkList is: %d\n", l);
  
  return 0;
}

void add(List* plist, int number){
  Node* p = (Node*)malloc(sizeof(Node));
  p->value = number;
  p->next = NULL;
  //在last后面加一个节点p
  Node* last = plist->head;
  if(last){
    while(last->next){
      last = last->next;
    }
    last->next = p;
  }else{
    plist->head = p;
  }
}

void print(List* plist){
  Node* last = plist->head;
  if(last){
    while(last->next){
      printf("%d\n", last->value);
      last = last->next;
    }
  }else{
    printf("%d\n", (plist->head)->value);
  }
}

//11:44写到delete;排错花了10min到11::55
void delete(List* plist, int n){
  int isDelete = 0;
  Node *p,*q;
  for(q=NULL, p=plist->head; p; q=p,p=p->next){ 
    if(p->value == n){
      if(q){
        q->next = p->next;
      }else{
        plist->head = p->next;
      }  
      free(p);
      isDelete = 1;
      break;
    }
  }
  if(!isDelete){    
    printf("Can't delete this number\n");
  }
}

int Length(List* plist){
  int j=0;
  Node* p = plist->head;
  while(p){
    p = p->next;
    j++;
  }
  return j;
}
