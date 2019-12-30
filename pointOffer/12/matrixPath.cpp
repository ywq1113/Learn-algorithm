#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/**************************************
 矩阵中坐标(row, col)

 行数rows,列数cols

 二维数组[row,col]在一维数组中转化为
 [row*cols+col]
 
 定义一个布尔值矩阵(bool值二维数组用来
 表示路径是否进入了每个格子

**************************************/


bool hasPath(char* matrix, int rows, int cols, char* str)
{

    //判断边界条件
    if(matrix==nullptr || row<1 || cols<1 || str==nullptr)
        return false;
    
    /********************************************
     visited开辟了rows*cols大小空间的bool数组
     void *memset(void* s, int c, size_t n)
     memset函数将已开辟的空间s的首n个字节设为值c
     在这里将visited中所有的bool值设为0
    *********************************************/
    bool *visited = new bool[rows*cols];
    memset(visited, 0, rows*cols);
    
    //遍历bool数组，如果某个路径具有所需str的所有元素则返回true
    int pathLength=0;
    for(int row=0;row<rows;++row){
        for(int col=0;col<cols;++col){
            if(hasPathCore(matrix, rows, cols, row, col, str,
                pathLength, visited))
                return true;
        }
    }
    
    delete[] visited;
    return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row,
                int col, const char* str, int& pathLength, bool* visited)
{
    //当所求的字符串为空时，直接返回true
    if(str[pathLength]=='\0')
        return true;

    bool hasPath = false;
    if(row>=0 && row<rows && col>=0 && col<cols
       && matrix[row*cols+col]==str[pathLength]
       && !visited[row*cols+col])
    {
        ++pathLength;
        visited[row*cols+col] = true;
        
        hasPath = hasPathCore(matrix, rows, cols, row, col-1, str, 
                            pathLength, visited)
               || hasPathCore(matrix, rows, cols, row-1, col, str, 
                            pathLength, visited)
               || hasPathCore(matrix, rows, cols, row, col+1, str, 
                            pathLength, visited)
               || hasPathCore(matrix, rows, cols, row+1, col, str, 
                            pathLength, visited);

        if(!hasPath)
        {
            --pathLength;
            visited[row*cols+col] = false;
        }
    }
    return hasPath;
}

