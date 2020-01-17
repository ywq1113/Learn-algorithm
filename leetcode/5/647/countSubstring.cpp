class Solution{
public:
    int countSubstrings(String s)
    {
        int N = s.size(), ans = 0;
        for(int center=0;center<=2*N-1;++center) //长度为N的字符串中，可能的中心有2N-1个
        //2N-1 = N + N-1 每个字符可能是中心 + 两个字符之间为中心
        {
            //left和right表示回文区间
            int left = center>>1;
            int right = left+center%2;
            while(left>=0 && right<N && s[left]==s[right])
            {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};

