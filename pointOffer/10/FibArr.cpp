#include <iostream>
#include <cstdio>

/*******************************
 输入一个整数n，求出斐波那契数列
 的第n项。
 1 1 2 3 5 8 13 ...
 *******************************
*/

using namespace std;

int Fibonacci_iter(int n)
{
    if(n<=2)  return 1;
    int FibNum1 = 1, FibNum2 = 1;
    
    int FibNum = FibNum1 + FibNum2;
    int i=2;
    while(i>=2 && i!=n){
        FibNum2 = FibNum1;
        FibNum1 = FibNum;
        FibNum = FibNum1 + FibNum2;
        i++;
    }
    return FibNum;
}

int Fibonacci_1(int n);

int Fibonacci_1(int n)
{
    if(n<=0) return 0;
    if(n==1) return 1;
    return Fiboacci_1(n-1)+Fiboacci_1(n-2);
}


int main(){
    printf("enter a number: \n");
    int n,res;
    scanf("%d",&n);
    res = Fibonacci_1(n);
    cout << "res = " << res << endl;
}
