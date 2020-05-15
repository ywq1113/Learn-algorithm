/*合并两个有序链表并返回合并后的新链表
 * 链表l1: 1->2->4
 * 链表l2: 1->3->4
 * 合并后链表为: 1->1->2->3->4->4
 */

#include <iostream>

using namespace std;

struct ListNode{
    int         val;
    ListNode*   next;
    ListNode(int x): val(x), next(NULL) {}  //当new ListNode(x)时，即创建了一个值为x，尾部为NULL的节点
};

class Solution{
public:
    ListNode* mergeTwoLists_Recursive(ListNode* l1, ListNode* l2)
    {
        //边界条件
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        if(l1==l2==nullptr)
            return nullptr;
        
        //比较头结点
        if(l1->val < l2->val){
            l1->next = mergeTwoLists_Recursive(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists_Recursive(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeTwoLists_Iteration(ListNode* l1, ListNode* l2)
    {
        //哑结点，放置于头结点后，数据节点之前，可简化代码，可避免处理边界条件
        ListNode* res = new ListNode(0);
        ListNode* workNode = res;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val < l2->val){
                workNode->next = l1;
                l1 = l1->next;
            }
            else{
                workNode->next = l2;
                l2 = l2->next;
            }
            workNode = workNode->next;
        }
        workNode->next = l1!=nullptr ? l1 : l2;
        return res->next;  //此时res包含了哑结点，所以返回res->next才是我们需要的合并后的链表
    }

};

int main(){
}  
