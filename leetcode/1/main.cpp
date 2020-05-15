#include <iostream>
#include <vector>
#include <unordered_map>
#include "twoSum.h"

using namespace std;

/**********************************************
 两数之和
 已知数组[2,7,11,15], target=9
 返回[0,1]
 注：不使用重复的数字
***********************************************/

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hash;
    vector<int> vec;
    for(unsigned int i=0;i<nums.size();++i)
    {
        int complement = target - nums[i];
        if(hash.find(complement)!=hash.end()){
            vec.push_back(i);
            vec.push_back(hash[complement]);
            return vec;
        }
        hash[nums[i]] = i;
    }
    return vec;
}


int main()
{
    vector<int> nums{2,7,11,15};
    int target = 11;
    Solution s;
    vector<int>* p = &s.twoSum(nums, target);
    vector<int> :: iterator iter;
    for(iter=p->begin();iter!=p->end();++iter)
        cout<< *iter << endl;
    return 0;
}
