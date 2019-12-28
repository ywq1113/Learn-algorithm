#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
 
class Solution {
public:
  int minNumberInRotateArray(vector<int> rotateArray) {
	  int size=rotateArray.size();
	  if (size==0)
		  return 0;
	  int left = 0, right = size-1;
	  int mid = 0;
	  while(rotateArray[left] >= rotateArray[right]){
		  //当左右相邻时，找到最小值，即右指针，此时可跳出循环
		  if(right - left == 1){
			mid = right;
			break;
		  }
		  //二分法确定中间值的办法
		  mid = left + (right - left) /2;
		  
		  if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]){
			return MinOrder(rotateArray,left,right);
		  }
		  
		  if (rotateArray[right] >= rotateArray[mid])
			  //如果中间值小于右侧, 那么中间值位于旋转后的递增数组, 在左侧和中间值进行二分查找
			right = mid;
		  else
			left = mid;
	  }//while
	  return rotateArray[mid];
  }

private:
  //顺序寻找最小值
  int MinOrder(vector<int> &num,int left, int right){
		int result = num[left];
		for (int i = left+1;i<right;++i){
			if(num[i] < result)
				result = num[i];
		}//for
		return result;
  }
}; //class Solution

//测试用例  
int main(){
	Solution s;
	vector<int> num = {2,2,2,2,1,2};
	int result = s.minNumberInRotateArray(num);
	cout << result << endl;
	return 0;
}
	