#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <memory>
#include "maxOfN.h"

using namespace std;

/*******************************************
void PrintNumber(char* number);
bool IsOverflow(char* number);
void PrintMaxOfNDigit(int n);
********************************************/

void PrintNumber(char* number)
{
    int nLen = strlen(number);
    if(nLen<=0)
        return;

    bool isPre0 = true;
    for(int i=0;i<nLen;++i)
    {
        if(isPre0 && number[i]!='0')
            isPre0 = false;
        if(!isPre0)
            printf("%c",number[i]);
    }

    printf("\t");
}

bool IsOverflow(char* number)
{
    bool checkOverflow = false;
    int carry = 0;
    int nLen = strlen(number);    

    for(int i=nLen-1;i>=0;i--)
    {
        int nSum = number[i]-'0'+carry;
        number[i] = nSum;
        if(i==nLen-1)
            nSum++;
        if(nSum>=10)
        {
            if(i==0)
                checkOverflow = true;
            else
            {
                nSum -= 10;
                carry = 1;
                number[i] = nSum + '0';
            }
        }
        else
        {
            number[i] = nSum + '0';
            break;
        }
    }
    
    return checkOverflow;
}

void PrintMaxOfNDigit(int n)
{
    if(n<=0)
        return;

    char* number = new char[n+1];
    memset(number,'0',n);
    number[n+1] = '\0';

    while(!IsOverflow(number))
        PrintNumber(number);

    delete[] number;
}

int main(){
    PrintMaxOfNDigit(3);
}
