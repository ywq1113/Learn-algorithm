#include <iostream>

using namespace std;

struct ListNode{
    int         val;
    ListNode*   next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr){
            int x = l1!=nullptr?l1->val:0;
            int y = l2!=nullptr?l2->val:0;
            int sum = carry + x + y;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(l1!=nullptr) l1 = l1->next;
            if(l2!=nullptr) l2 = l2->next;
        }

        //判断例子[5]和[5]，输出[0,1]
        if(carry>0)
            curr->next = new ListNode(carry);
        
        //释放掉建立的哨兵节点
        ListNode* ptrdel = res;
        res = res->next;
        delete ptrdel;

        return res;
    }
};
