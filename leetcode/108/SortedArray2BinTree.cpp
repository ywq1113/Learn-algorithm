#include<iostream>
#include<cstdio>

/*
 *一个按照升序排列的数组，转换为一个高度平衡二叉搜索树;
 *本题中，一个高度平衡二叉树是指一个二叉树每个节点的左右
 *两个子树的高度差的绝对值不超过1;
 *示例:
 *给一个有序数组[-10,-3,0,5,9]
 *可能的答案是[0,-3,5,-10,null,null,9]
 */

/* 题解:
 * 二叉搜索树特点左<根<右且高度平衡
 * 可以将数组从中间分开，左边为左子树，右边为右子树
 */

class Solution{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
    int len = nums.size();
    if(len == 0)
        return nullptr;
    int mid = len/2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    if(mid>=0)
        sortedArray(nums,0,mid-1,&(root->left));
    if(len-1>mid)
        sortedArray(nums,mid+1,len-1,&(root->right));
    return root;
    }

    void sortedArray(vector<int> &nums, int start, int end, TreeNode** node)
    {
        if(start>end)
            return;
        else{
            int mid = (start+end)/2;
            TreeNode* tmp = new TreeNode(nums[mid]);
            *node = tmp;
            if(mid>s)
                sortedArray(nums,s,mid-1,&(tmp->left));
            if(mid<s)
                sortedArray(nums,mid+1,end,&(tmp->right));
        }
    }

};
        

