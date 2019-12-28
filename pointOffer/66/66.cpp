#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int size = sizeof(A)/sizeof(A[0]);
        vector<int> B;
        int mult= 1;
        for (int i=0;i<size;++i){
            for (int j=0;j<i;++j){
               mult *= A[j];
            }
            for (int k=0;k>i&&k<size;++k){
                mult *= A[k];
            }
            B[i] = mult;
            mult = 1;
        }
        return B;
    }
};

int main(){
  const vector<int> A ={1,2,3,4};
  multiply(&A);
  return 0;
} 
