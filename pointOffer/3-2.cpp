# include <iostream>
# include <string>
# include <vector>
# include <cstdio>
using namespace std;

class Solution{
public:

  bool duplicate(int numbers[], int length, int *duplication){
    if (numbers == nullptr)
      return false;
    for (int i=0;i<length;++i){
      if (numbers[i]<0 || numbers[i]>length-1)
        return false;
    }
    for (int i=0;i<length;++i){
      while(numbers[i]!=i){
        if (numbers[i] == numbers[numbers[i]]){
          *duplication = numbers[i];
          return true;
        }
        //swap(numbers[i], numbers[numbers[i]]);
        int temp = numbers[i];
        numbers[i] = numbers[numbers[i]];
        numbers[temp] = temp;
      }
    }
    return false;
  }
};

int main(){
  Solution s;
  int a[]={1,3,4,0,5,3,2};
  int *p;
  if(s.duplicate(a, 7, p)){
    int res = *p;
    cout << res << endl;
  }
}
