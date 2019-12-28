#ifndef _LINKLIST_H
#define _LINKLIST_H

//单向链表的定义
struct ListNode
{
  int   Value;
  ListNode* Next;
};

//往链表末尾添加一个节点
void AddToTail(ListNode** pHead, int value);
void Delete(ListNode** pHead, int value);

void AddToTail(ListNode** pHead, int value)
{
  ListNode* p = new ListNode(); //新建一个节点
  p->Value = value;
  if(pHead==nullptr)
    *pHead = p;
  else{
    ListNode* last = *pHead;
    while(last->Next)
      last = last->Next;
    last->Next = p;
  }
}

void Delete(ListNode** pHead, int value)
{
  //指向指针的指针(pHead)为空或头结点(*pHead)为空
  if (pHead == nullptr || *pHead == nullptr)
    return;
  ListNode* p = nullptr; //p指向要删除的节点
  //删除头结点时
  if((*pHead)->Value == value){
    p = *pHead;
    *pHead = (*pHead)->Next;
  }else{
    ListNode* q = *pHead;
    while(q->Next != nullptr && q->Next->Value != value)
      q = q->Next;
    if(q->Next != nullptr && q->Next->Value == value){
      p = q->Next;
      q->Next = q->Next->Next;
    }
  }
  //要删除的节点不为空时，进行删除操作
  if(p!=nullptr){
    delete p;
    p == nullptr;
  }
}

#endif
