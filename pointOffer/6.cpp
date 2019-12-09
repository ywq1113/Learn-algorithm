#include "LinkList.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdio>

//typedef struct node{
//  int value;
//  struct node* Next;
//} ListNode;


void PrintListReversingly_Iteratively(ListNode* pHead)
{
  std::stack<ListNode*>nodes;
  ListNode* pNode = pHead;
  while(pNode != nullptr){
    nodes.push(pNode);
    pNode = pNode->Next;
  }

  while(!nodes.empty()){
    pNode = nodes.top();
    printf("%d\t", pNode->Value);
    nodes.pop();
  }
}

//使用递归的代码很简洁，但是容易导致函数调用栈溢出
void PrintListReversingly_Recursively(ListNode* pHead)
{
  if(pHead!=nullptr){
    if(pHead->Next!=nullptr)
      PrintListReversingly_Recursively(pHead->Next);
    printf("%d\t", pHead->Value);
  }
}

int main(int argc, const char* argv[]){
  int number;
  ListNode* *pHead = nullptr;
  do{
    if (number!=-1){
      scanf("%d", &number);
      AddToTail(pHead, number);
    }
  }while(number!=-1);

  ListNode* p = *pHead;
  PrintListReversingly_Iteratively(p);
}
  
