#include <iostream>
#include <cstdio>

using namespace std;

/******************************************
 一根长度为n的绳子，剪成m段(m和n均为整数且
 大于1)。每段绳子长度记为k[0],k[1],...,k[m]
 请问k[0]*k[1]*...*k[m]最大值为多少？
 eg. n=8 剪成3段，2,3,3时乘积最大为18。 
*******************************************/

int maxProductAfterCutting_solution(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;

    int* products = new int[length+1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for(int i=4;i<=length;++i)
    {
        max=0;
        for(int j=1;j<=i/2;++j)
        {
            int product = products[j]*products[i-j];
            if(max<product)
                max = product;
            products[i] = max;
            printf("products[i] = %d, i = %d\n", products[i], i);
        }
        //为什么要放在内层for循环内？能否放在这里？
        //printf("max = %d\n", max);
        //products[i] = max;
    }

    max = products[length];
    delete[] products;

    return max;
}

int main(){
    int res = maxProductAfterCutting_solution(8);
    printf("res = %d\n", res);
}
