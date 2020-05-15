#include <iostream>
#include <vector>
#include <string>

using namespace std;

/***************************************
 求字符串中没有重复字符的最长子串长度
 解法：
 1.循环
 2.哈希表，滑动窗口
****************************************/

int lengthOfLongestSubstring(string s)
{
    if(s.size()==0)
        return 0;

    int start=0, end=0, length=0, res=0;
    while(end<s.size())
    {
        for(size_t i=start;i<end;++i)
        {
            if(s[end]==s[i]){
                start = i+1;
                length = end-i;
                break;
            }
        }
        end++;
        length++;
        res = max(res,length);
    }
    return res;
}


/***************************************
 解法2 set+滑动窗口
****************************************/
int lengthOfLongestSubstring_2(string s)
{
    if(s.size()==0)
        return 0;

    int i=0, j=i, res=0;
    set<char> hashset;
    while(i<s.size() && j<s.size())
    {
        if(!hashset.count(s[j]))
        {
            hashset.insert(s[j++]);
            res = max(res, j-i);
        }
        else
        {
            hashset.erase(s[j]);
            i++;
        }
    }
    return res;
}
