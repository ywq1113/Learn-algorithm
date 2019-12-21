#include <iostream>

using namespace std;

/* 选择排序
 * 时间复杂度O(N2),for循环套了一个ScanForMin的for循环
 */

void selectionSort(int A[], int N)
{
    for(int i=0;i<N;i++){
        /*从A[i]到A[N-1]中找到最小值，将其位置赋给MinPosition
         *将未排序部分的最小元换到有序部分的最后位置
         */
        MinPosition = ScanForMin(A, i, N-1);
        swap(A[i], A[MinPosition]);
    }
}
