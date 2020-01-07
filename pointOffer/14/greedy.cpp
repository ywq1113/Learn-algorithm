#include <iostream>         
#include <cstdio>                                                                                       
                                                                                           
using namespace std;

/*******************************************
 贪婪算法：每一步可以做出一个贪婪的选择，确
 定这一步可以获得最优解。
 考虑k[0],k[1],...,k[m]中可能包含的数
 4 = 2*2
 5 < 2*3
 6 < 3*3
 7 < 2*5 < 2*2*3 
 可以得知最优解中只有2和3。
 且当n>5时，可发现2*(n-2)<3*(n-3)，所以优先
 切长度为3的绳子。
********************************************/



int maxProductAfterCutting_solution(int length)
{
    if(length<2)   
        return 0;  
    if(length==2)  
        return 1;  
    if(length==3)  
        return 2;

    //长度为3的绳子段数，仅剩下长度为4时切2*2
    int timesOf3 = length/3;
    if(length-timesOf3*3==1)
        timesOf3 -= 1;

    int timesOf2 = (length - timesOf3*3)/2;

    return (int)(pow(3,timesOf3*3)) * (int)(pow(2,timesOf2));
}   
