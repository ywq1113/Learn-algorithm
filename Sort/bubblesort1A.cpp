# include <iostream>
# include <string>
# include <vector>
using namespace std;

/*冒泡排序
 * 时间复杂度O(n2)
 */

void bubblesort1A(int A[], int n){
  bool sorted = false;
  while(!sorted){
    for(int i=1;i<n;i++){
      sorted = true;
      if(A[i-1]<A[i]){
        swap(A[i-1], A[i]);
        sorted = false;
      }
    }
    n--;
  }
}

int main(){
  int a[7]={1,3,4,2,0,6,5};
  bubblesort1A(a, 7);
  for(int i=0;i<7;i++){
    cout << "i= " << i << " a[i]= " << a[i] << endl;
  }
  return 0;
}
