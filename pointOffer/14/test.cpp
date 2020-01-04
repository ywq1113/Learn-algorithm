#include <iostream>
#include <cstdio>

using namespace std;

int maxProductAfterCutting_solution(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;

    int* res = new int[length+1];
    res[0] = 0;
    res[1] = 1;
    res[2] = 2;
    res[3] = 3;

   /*****************************************************
     为什么把max放在这里，可以放在循环内部吗？
     答：放在循环外部，可以作为返回值。如果在函数末尾直接
     返回res[length]就没有合适的机会释放该指针的内存，进
     行delete[]。
   ******************************************************/
    int max = 0;

    for(int i=4;i<=length;++i)
    {
        int max = i-1;
        for(int j=1;j<=i/2;++j)
        {
            if(max<res[j]*res[i-j])
                max = res[j]*res[i-j];
            res[i] = max;
        }
    }
    max = res[length];
    delete[] res;

    return max;
}

int main(){
    int length=0, res=0;
    printf("enter a number: ");
    scanf("%d\n", &length);
    printf("length = %d\n", length);
    res = maxProductAfterCutting_solution(length);
    printf("res = %d\n", res);
    return 0;
}
