#include<iostream>
#include<cstdio>
#include<vector>

/*合并两个数组nums1和nums2
 * nums1的元素为m个，nums2的元素为n个
 * 例子如下
 * nums1 = [1,2,3,4,0,0,0];  m=4
 * nums2 = [1,2,3];          n=3
 * 合并后的nums1 = [1,1,2,2,3,3,4]
 */

/*解法：归并排序
 */

class Solution{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = n+m-1;
        while(m-1>=0 || n-1>=0)
        {
            /* &&优先级高于||,因此先执行m-1>=0 && nums1[m-1]>nums2[n-1]
             * 当nums2中的数走到头以后，即n-1<0
             */
            if(n-1<0 || m-1>=0 && nums1[m-1]>nums2[n-1])
            {
                nums1[i] = nums2[m-1];
                --m;
                --i;
            }
            else
            {
                nums1[i] = nums2[n-1];
                --n;
                --i;
            }
        }
    }
};

