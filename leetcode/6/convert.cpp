#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

/*Z字形变换
 *如LEETCODEISHIRING转换为三行
 *L   C   I   R
 *E T O E S I I G
 *E   D   H   N
 *输出LCIRETOESIIGEDHN
 */


/*思路
 * 从左至右迭代字符串
 * 确定字符位于Z字形图案的哪一行
 * 构建字符串列表
 * 遍历，将字符串列表每一行加起来
 */

class Solution{
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1)  return s;

        int n = (int)s.size();
        int curRow = 0;
        bool godown = false;
        
        vector<string> rows(min(numRows, n));
        for(char c : s){
            rows[curRow] += c;
            if(curRow==0 || curRow == numRows-1)  godown = !godown;
            curRow += godown ? 1 : -1;
          /*等价于
           *if(godown)  curRow -= 1;
            else  curRow += 1;
           */
        }

        string res;
        for(string row : rows){
            res += row;
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s("leetcode");
    int num;
    printf("Enter the number of rows:");
    scanf("%d", &num);
    string res = sol.convert(s, num);
    //printf("%s", res);
    cout << res << endl;
}  
