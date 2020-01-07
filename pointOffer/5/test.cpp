#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void blankSpaceReplace(char str[], int length)
{
    if(str==nullptr || length<0)
        return;

    int index=0,cntBlank=0;
    while(str[index]!='\0')
    {
        if(str[index]==' ')
            ++cntBlank;
        ++index;
    }
    //cout << "index = " << index << endl;
    //cout << "cntBlank = " << cntBlank << endl;
    int newLength = index+cntBlank*2;
    if(newLength>length)
        return;

    int p1 = index, p2 = newLength;
    while(p1>=0 && p1<p2)
    {
        if(str[p1]==' ')
        {
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
        }
        else{
            str[p2--] = str[p1];
        }
        --p1;
    }
}

int main()
{
    char str[] = "we are happy";
    blankSpaceReplace(str, 40);
    cout << str << endl;
}    
