#include <iostream>
#include <cstdio>

using namespace std;

/***********************************
 C++的位运算符& | ^ << >>
 举例
 unsigned short x=3, y=5
     x = 00000000 00000011(3)
     y = 00000000 00000101(5)
 
 x & y = 00000000 00000001(1)
 x | y = 00000000 00000111(7)
 x ^ y = 00000000 00000110(6)

 x >> 2 = 00000000 00000000(0)
 y >> 2 = 00000000 00000001(1)
 x << 2 = 00000000 00001100(12)
 y << 2 = 00000000 00010100(20)
***********************************/

/**********************************
 在这个函数中包含了一个致命的问题，
 有可能会陷入死循环中，你知道问题出
 在哪里嘛？应该如何解决它？
***********************************/

int NumberOf1(int n)
{
    int count = 0;
    while(n)
    {
        if(n&1)
            count++;
        n = n>>1;
    }
    return count;
}

//常规解法
int NumberOf1_2(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        /********************************
              19 = 10011
               2 = 00010
               4 = 00100
               8 = 01000
              16 = 10000
         19 & 1  = 00001(1>0)  count = 1
         19 & 2  = 00010(2>0)  count = 2
         19 & 4  = 00000(0=0)  count = 2
         19 & 8  = 00000(0=0)  count = 2
         19 & 16 = 10000(16>0) count = 3  
        ********************************/        
        if(n&flag)
            count++;
        flag = flag << 1;
        cout << "flag = " << flag << endl;
    }
    return count;
}

int NumberOf1_3(int n)
{
    int count = 0;
    unsigned int flag = 1;
    for(;flag<=n;)
    {
        if(n&flag)
            count++;
        flag = flag << 1;
        cout << "flag = " << flag << endl;
    }
    return count;
}
    
//一种很惊艳的方法
int NumberOf1_4(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n = (n-1)&n;
    }
    return count;
}

int main(){
    int n=0;
    cin >> n;
    int res = NumberOf1_4(n);
    cout << res << endl;
    return 0;
}

