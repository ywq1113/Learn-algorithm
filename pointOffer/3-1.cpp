# include <iostream>
# include <string>
# include <vector>
# include <cstdio>
using namespace std;

void bubbleSort(int A[], int n);
void bubbleSort(int A[], int n){
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

class Solution{
public:
  bool duplicate(int numbers[], int length, int *duplication){
    int res=0;
    if (numbers == nullptr && length <= 0)
      return false;
    for (int i=0;i<length;++i){   //for循环中的++i和i++区别：i++需要一个临时变量申请空间来存储返回自增之前的值，然后再释放空间，耗时增加
      if (numbers[i] < 0 || numbers[i] > length-1)
        return false;
    }
    bubbleSort(numbers, length);
    for(int i=1;i<length;i++){
      if (numbers[i] == numbers[i-1] || numbers[i] == numbers[i+1]){
        return true;
        duplication = &numbers[i];
      }
      else
        return false;
    }
    return false;
  }
};

int main(){
  Solution s;
  int a[7]={2,2,1,4,1,3,6};
  int *res;
  if(s.duplicate(a, 7, res))
    cout << "duplication= " << res << endl;
  else
    cout << "No duplication" << endl;
  return 0;
}

