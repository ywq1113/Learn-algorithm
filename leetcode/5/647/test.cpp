# include <iostream>
# include <string>
# include <vector>
# include <cstdio>
using namespace std;

int countPalSubstring(string s)
{
    if(s.size()<2)
        return s.size();

    int res=0;
    int n = s.size(), center=2*n-1;

    for(int i=0;i<=center;++i)
    {
        int left = i>>1;
        int right = left+i%2;
        while(left>=0 && right<n && s[left]==s[right])
        {
            res++;
            left--;
            right++;
        }
    }
    return res;        
}

