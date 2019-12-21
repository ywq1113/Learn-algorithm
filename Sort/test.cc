#include<iostream>
#include<string>
#include<vector>

using namespace std;
void bubbleSort(int array[], int n);

void bubbleSort(int array[], int n){
  bool res = false;
  while(!res){
    res = true;
    for (int i=1;i<n;++i){
      int temp;
      if (array[i-1]>array[i]){
         //swap(array[i-1], array[i]);
         temp = array[i-1];
         array[i-1] = array[i];
         array[i] = temp;
         res = false;
      }
    }
    n--;
  }
}

int main(){
  int a[7]={2,2,1,4,4,6,5};
  bubbleSort(a, 7);
  for(int i=0;i<7;++i){
    cout << "i= " << i << " a[i]= " << a[i] << endl;
  }
  return 0;
}

