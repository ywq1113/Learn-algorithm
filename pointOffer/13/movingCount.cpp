#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include "movCou.h"

using namespace std;

/****************************************
 m行n列的方格，机器人在坐标(0,0)处出发，
 每次可以向左，右，上，下移动一格，但不能
 进入坐标数位之和大于k的格子。
 eg. k=18，不能进入（35,38），因为有
     3+5+3+8=19>18
 请问机器人能够到达多少个格子？
*****************************************/


int movingCount(int threshold, int rows, int cols)
{
    if(threshold<0 || rows<=0 || cols<=0)
        return 0;

    bool* visited = new bool[rows*cols];
    for(int i=0;i<rows*cols;++i)
        visited[i] = false;
    
    int count = movingCountCore(threshold, rows, cols,
                                0, 0, visited);
    delete[] visited;
    return count;
}

int movingCountCore(int threshold, int rows, int cols,
                    int row, int col, bool* visited)
{
    int count = 0;
    if(check(threshold, rows, cols, row, col, visited))
    {
        visited[row*cols+col] = true;

        count = 1 + movingCountCore(threshold, rows, cols,
                                row-1, col, visited)
                  + movingCountCore(threshold, rows, cols,
                                row+1, col, visited)
                  + movingCountCore(threshold, rows, cols,
                                row, col-1, visited)
                  + movingCountCore(threshold, rows, cols,
                                row, col+1, visited);
    }
    return count;
}

bool check(int threshold, int rows, int cols, 
            int row, int col, bool* visited)
{
    if(row>=0 && col>=0 && row<rows && col<cols &&
        getDigitSum(row)+getDigitSum(col)<=threshold
       && !visited[row*cols+col])
        return true;

    return false;
}

int getDigitSum(int i)
{
    int res = 0;
    while(i>0){
        res = res*10 + i%10;
        i = i/10;
    }
    return res;
}

int main(){
    return 0;
}
