#include <iostream>
#include <string>
#include <vector>

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
 */

class Solution{
public:
    string convert(sting s, int numRows)
    {
        if(numRows == 1)  return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        int curRow=0
        bool goingDown = false;

        for(char c : s){
            
