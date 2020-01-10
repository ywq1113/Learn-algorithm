#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>

using namespace std;

/*********************************
 打印从1到最大的n位数。例如输入3，
 则打印1,2,3,...998,999.
 当n值很大时，需要考虑大数问题。
**********************************/

bool Increment(char* number);
void PrintNumber(char* number);

void printMax(int n)
{
    if(n<=0)
        return;

    char* number = new char[n+1];
    //将前n个字符设为'0'，最后一个字符设为'\0'
    memset(number,'0',n);
    number[n] = '\0';

    while(!Increment(number))
    {
        PrintNumber(number);
    }

    delete[] number;
}

bool Increment(char* number)
{
    /***************************************
     该函数判断字符数组能否增加，并且在没有
     达到最值时将字符数组对应的数字增加，判断
     是否到达了最大n位数.实现了O(1)时间效率，
     用strcmp则是O(n)的时间复杂度。
    while(number[n-1]=='9' && n==count)
    {
        int count = 1;
        count++;
        n--;
    }
    ***************************************/
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);
    for(int i = nLength-1;i>=0;--i)
    {
        //字符减去'0'就转换为数字
        int nSum = number[i]-'0'+nTakeOver;
        //将number+1,这个判断条件没看懂，why
        if(i==nLength-1)
            nSum++;
        if(nSum>=10)
        {
            //如果在首位处进位，则返回true
            if(i==0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0'+nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

/************************************
 printf函数虽然可以直接打印字符，但是
 不符合我们的习惯，如098，我们需要的
 是打印出98。这就是PrintNumber要实现
 的功能，忽略前面补的0。
 实现：碰到第一个非0字符的时候，才开始
 打印，一直到字符数组末尾。
 ************************************/
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);
    
    for(int i=0;i<nLength;++i)
    {
        if(isBeginning0 && number[i]!='0')
            isBeginning0 = false;
        if(!isBeginning0)
            printf("%c",number[i]);
    }
    printf("\t");
}

int main()
{
    printMax(3);
} 
