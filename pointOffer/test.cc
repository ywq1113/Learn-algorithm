# include <iostream>
# include <string>
# include <vector>
using namespace std;


class Solution{
public:
  bool duplicate(int numbers[], int length, int *duplication){
    int res=0;
    if (numbers == nullptr && length <= 0)
      return false;
    for (int i=0;i<length;++i){   //for循环中的++i和i++区别：i++需要一个临时变量申请空间来存储返回自增之前的值，然后再释放空间，耗时增加
      if (numbers[i] < 0 || numbers[i] > length-1)
        return false;
      while (numbers[i]!=i){
        swap(numbers[i], numbers[numbers[i]]);
        if(numbers[i]==numbers[numbers[i]]){
          res = numbers[i];
          break;
        }
      }
    }
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
