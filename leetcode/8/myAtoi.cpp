#include<iostream>
#include<string>
#include<ctype.h>
#include<cstdio>
#include<limits.h>
/*
 * ctype.h文件包含了isdigit函数，判断字符是否为0~9
 * limits.h文件引入了INT_MAX和INT_MIN
 */

/* 题目描述
 * 
 * 实现一个atoi函数，使其能将字符串转换为整数
 * 丢弃开头的空格字符
 * 搜索到的第一个正号/负号字符作为整数的正负号
 * 字符串中除了有效的整数部分，多余的部分被忽略
 * 
 * 注意：字符串中的第一个非空格字符不是一个有效整数字符、
 * 字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换
 * 
 * 示例：
 * 输入 "  -4193 with words"
 * 输出 -4193
 * 输入 "words and 987"
 * 输出 0
 * 输入 "-91283472332"
 * 输出 -2147483648 (输入超过32位有符号整数的范围，返回INT_MAX)
 */

/*思路:
 * 过滤字符串 （空字符，首位非数字）这些统统返回0
 * 判断正负号
 * 轮询读取，直到非数字的字符出现
 * 溢出判断
 */




using namespace std;

class Solution{
public:
    int myAtoi(string str)
    {
        int i=0, res=0, flag=1;        

        //忽略空格字符
        while(str[i]==' ')  
            i++;
        
        //判断正负号
        if(str[i]=='-') 
            flag = -1;
        if(str[i]=='+' || str[i]=='-') 
            i++;

        while(i<str.size() && isdigit(str[i])){
            //str[i]最后会有一个字符'0'，需要把它弃掉再转换为int; int类型加上'0'则可以隐性转换为char类型
            int r = str[i]-'0';
            //处理整型溢出的情况
            //int最大值为2,147,483,647 当十位数之后相同但个位数大于7时也属于溢出
            if(res>INT_MAX/10 || (res==INT_MAX/10 && r>7)){
                return flag>0 ? INT_MAX : INT_MIN;
            }
            res = res*10 + r;
            i++;
        }

        return flag>0 ? res : -res;
    }
};

/* 测试用例
 * 输入:
 * "-91283472332"   考察越界问题(int类型最大值与最小值)
 * “ "              考察字符为空
 * "+"              考察第一个非空字符是+或-
 * "  -1113" 
 */

int main(){
    Solution s;
    //printf("Enter a string:\n");
    string str;
    //scanf("%s", &str);
    string str1(" -11wq");
    int res;
    res = s.myAtoi(str1);
    printf("%d",res);
    return 0;
} 
