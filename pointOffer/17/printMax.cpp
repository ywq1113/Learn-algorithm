#include <iostream>
#include <string>

using namespace std;

/*********************************
 打印从1到最大的n位数。例如输入3，
 则打印1,2,3,...998,999.
 当n值很大时，需要考虑大数问题。
**********************************/

void printMax(int n)
{
    if(n<=0)
        return;

    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';

    
