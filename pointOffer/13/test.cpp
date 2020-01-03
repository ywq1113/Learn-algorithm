#include <iostream>
#include "movCou.h"
#include <cstdio>

using namespace std;

/**************************
 2020.1.3 22:16
 重写movingCount.cpp file
***************************/

int movingCount(int threshold, int rows, int cols)
{
    if(threshold<=0 || rows<1 || cols<1)
        return 0;

    bool* visited = new bool[rows*cols];
    for(int i=0;i<=rows*cols;++i)
        visited[i] = false;

    int count = 0;
    for(int row=0;row!=rows;++row)
    {
        for(int col=0;col!=cols;++col)
        {
            if(movingCountCore(threshold, rows, cols, 
               row, col, visited))
                count++;
        }
    }
    
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

bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
    if(row>=0 && row<rows && col>=0 && col<cols && 
       getDigitSum(row) + getDigitSum(col)<=threshold
      && !visited[row*cols+col])
        return true;

    return false;        
}

int getDigitSum(int i)
{
    int res=0;
    while(i>0){
        res += res*10+i%10;
        i /= 10;
    }
    return res;
}

int main(){
    return 0;
}
