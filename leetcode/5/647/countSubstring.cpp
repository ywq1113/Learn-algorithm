class Solution{
public:
    int countSubstrings(string s)
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
    
    int countSubstrings_2(string s)
    {
        char[] A = new char[2*s.size()+3];
        A[0] = '@';
        ...

        int[] Z = new int[s.size()];
        int center=0, right=0;
        
    }
};

class Solution {
    public int countSubstrings(String S) {
        char[] A = new char[2 * S.length() + 3];
        A[0] = '@';
        A[1] = '#';
        A[A.length - 1] = '$';
        int t = 2;
        for (char c: S.toCharArray()) {
            A[t++] = c;
            A[t++] = '#';
        }

        int[] Z = new int[A.length];
        int center = 0, right = 0;
        for (int i = 1; i < Z.length - 1; ++i) {
            if (i < right)
                Z[i] = Math.min(right - i, Z[2 * center - i]);
            while (A[i + Z[i] + 1] == A[i - Z[i] - 1])
                Z[i]++;
            if (i + Z[i] > right) {
                center = i;
                right = i + Z[i];
            }
        }
        int ans = 0;
        for (int v: Z) ans += (v + 1) / 2;
        return ans;
    }
}

