# include <iostream>
# include <string>
# include <vector>
# include <cstdio>
# include <unordered_map>
# include <cstddef>

using namespace std;

/**********************************************
 三数之和
 给定数组[-1,0,1,2,-1,-4]，判断是否存在三个数和
 为0。找出所有不重复的三元数组。
 返回：
 [ [-1,0,1],[-1,-1,2] ]

 注意：此题关键点要去重，所以思路可以是先排序
***********************************************/


vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> vec;
    int twoSum=0;
    unordered_map<int, int> hash;

    sort(nums.begin(),nums.end());
    //边界条件
    if(nums.size()<3 || nums[0]<0 || nums[nums.size()-1]>0)
        return vec;

    for(size_t i=0;i<nums.size()-1;++i) //size_t被设计为适用于多个平台无限大的类型，位于cstddef头文件中
    {
        if(nums[i]>0)   break;
        if(i>0 && nums[i]==nums[i-1])  continue;  //会跳过当前循环中的代码，强迫开始下一轮循环

        int target = 0-nums[i];
        int p1eft = i+1, pright = nums.size()-1;
        while(pleft<pright)
        {
            if(nums[pleft]>target)  break;
            
        }
    }    
