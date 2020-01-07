#include <iostream>
#include <string.h>
#include <cstdio>
#include "HasPath.h"

using namespace std;

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(matrix==nullptr || rows<1 || cols<1 || str==nullptr)
        return false;

    bool* visited = new bool[rows*cols];
    memset(visited, 0, rows*cols);

    int pathLength = 0;
    for(int row=0;row!=rows;++row){
        for(int col=0;col!=cols;++col){
            if(hasPathCore(matrix, rows, cols, row, col,
                str, pathLength, visited))
                return true;
        }
    }

    delete[] visited;
    return false;
}

//易出错的参数，const matrix，const str，int& pathLength
bool hasPathCore(const char* matrix, int rows, int cols, int row,
                 int col, const char* str, int& pathLength, bool* visited)
{
    if(str[pathLength]=='\0')
        return true;

    bool hasPath = false;
    if(row>=0 && row<rows && col>=0 && col<cols && !visited[row*cols+col]
       && str[pathLength]==matrix[row*cols+col])
    {
        ++pathLength;
        visited[row*cols+col] = true;

        //bool hasPath = false;
        hasPath = hasPathCore(matrix, rows, cols, row-1, col,
                  str, pathLength, visited)
               || hasPathCore(matrix, rows, cols, row+1, col,
                  str, pathLength, visited)
               || hasPathCore(matrix, rows, cols, row, col-1,
                  str, pathLength, visited)
               || hasPathCore(matrix, rows, cols, row, col+1,
                  str, pathLength, visited);
        if(!hasPath)
        {    
            --pathLength;
            visited[row*cols+col]=false;
        }
    }
    return hasPath;
}

int main(){
    return 0;
}