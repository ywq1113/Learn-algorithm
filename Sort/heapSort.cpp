#include <iostream>

using namespace std;

/*堆排序
 * 时间复杂度O(NlogN)
 * 需要开辟额外的O(N)空间,复制元素也需要时间
 */

void heap_sort_1(int A[], int N)
{
    BuildHeap(A);        //O(N)
    for(i=0;i<N;++i)
        TmpA[i] = DeleteMin(A);  //O(logN)
    for(i=0;i<N;++i)             //O(N)
        A[i] = TmpA[i];
}

void heap_sort_2(int A[], int N)
{

}

