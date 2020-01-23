# include <iostream>
# include <string>
# include <vector>
# include <cstdio>

using namespace std;

/***********************************************************
 * 正则表达式匹配
 * 字符'.'表示任意一个字符
 * 字符'*'表示它前面的字符可以出现任意次数(含0次)
 * 匹配是指字符串(str)中所有字符匹配整个模式(pattern)
 * 例如字符串"aaa"与模式"a.a"和"ab*ac*a匹配
 * 与"aa.a"和"ab*a"不匹配
************************************************************/
bool match(char* str, char* pattern)
{
    //凡是指针作为参数，均要考虑为空指针的情况
    if(str==nullptr || pattern==nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(char* str, char* pattern)
{
    //这两条if语句作为了递归的终点
    if(*str=='\0' && *pattern=='\0')
        return true;

    if(*str!='\0' && *pattern=='\0')
        return false;

    //pattern不为空，且包含'*'时
    if(*(patter+1)=='*')
    {
        //*前面部分字符串与模式一致时
        if(*pattern==*str || (*pattern=='.' && *str!='\0'))
            return matchCore(str+1, patter+2)  //字符串往后移动一位;模式往后移动两位;即"aba"和"ab*a"
                || matchCore(str+1,pattern)    //字符串往后移动一位;模式不动;即"aaab"和""a*b"
                || matchCore(str, pattern+2);  //字符串不动;模式移动两位;即"aab"和"ac*ab"
        else
            return matchCore(str, pattern+2);
    }
    
    if(*str==*pattern || (*pattern =='.' && *str!='\0'))
        return matchCore(str+1, pattern+1);

    return false;
}

/***************************************************************
 * 测试用例
 * str : "aba"
 * pattern : "..." ".*"  ".b*a"
****************************************************************/
