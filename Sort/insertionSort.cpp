#include <iostream>

using namespace std;

/*插入排序
 * 从小到大进行排列
 * 时间复杂度
 */

void InsertionSort( ElementType A[], int N )
{
     int P, i;
     ElementType Tmp;
      
     for ( P=1; P<N; P++ ) {
         Tmp = A[P];                /* 取出未排序序列中的第一个元素,第0个位置是已知的*/
         for ( i=P; i>0 && A[i-1]>Tmp; i-- )
             A[i] = A[i-1];         /*已排序序列中元素右移*/
         A[i] = Tmp;                /* 放进合适的位置 */
     }
}
