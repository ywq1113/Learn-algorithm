#include "LinkList.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdio>
#include <exception>

typedef struct BinaryTreeNode{
  int                     value;
  struct BinaryTreeNode*  Left;
  struct BinaryTreeNode*  Right;
} BT;

/*在前序遍历和中序遍历中确定左右子树的子序列
 *下面代码为递归代码
 */
BT* ConstructCore
(
    int* startPreorder, int* endPreorder,
    int* startInorder,  int* endInorder
);

BT* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    return ConstructCore(preorder, preorder+length-1,inorder,inorder+length-1);
}

BT* ConstructCore
(
    int* startPreorder, int* endPreorder,
    int* startInorder,  int* endInorder
)
{
    int rootValue = startPreorder[0];
    BT* root = new BinaryTreeNode();
    root->value = rootValue;
    root->Left = root->Right = nullptr;

    if(startPreorder == endPreorder)
    {
        if(startInorder==endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw std::exception("Invaid input.");
    }

    int* rootInorder = startInorder;
    while(rootInorder<=endInorder && *rootInorder!=rootValue)
        ++rootInorder;
    
    if(rootInorder==endInorder && *rootInorder!=rootValue)
        throw std::exception("Invalid input.");

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength>0)
    {
        root->Left = ConstructCore(startPreorder+1,
                     leftPreorderEnd, startInorder, rootInorder-1);
    if(leftLength<endPreorder - startPreorder)
    {
        root->Right = ConstructCore(leftPreorderEnd+1,
                      endPreorder, rootInorder, endInorder);
    }
    return root;
}
