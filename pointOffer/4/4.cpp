# include <iostream>
# include <string>
# include <vector>
using namespace std;

//class Solution{
//public:
  void Find(int target, vector<vector<int> > array){
    int row=array.size();
    int col=array[0].size();
    int i,j;
    for(i=row-1,j=0;i>=0&&j<col;){
      if (target = array[i][j])
        break;
      if (target < array[i][j]){
        i--;
        continue;
      }
      if (target > array[i][j]){
        j++;
        continue;
      }
    }
    cout << "the target locals at " << i << j << endl;
  }
//};

int main(){
  //vector<vector<int> > array  
  //vector <int> vec(10,90); 将10个一维动态数组初始化为90
  int m,n;
  cout << "Input two numbers to generate m*n array: " << endl;
  cin >> m >> n;
  vector<vector<int> > array(m,vector<int>(n)); //初始化m*n的二维动态数组
  //vec[0][0]=1; 对二维数组赋值的方法
  //vec[0][1]=2;
  int i,j, k=0;
  for (i=0;i<m;i++){
    for (j=0;j<n;j++){
       array[i][j] = k;
       k++;
       cout << array[i][j] << endl;
    }
 }
 cout << Find(5, vector<vector<int> > array) << endl; //报错expected primary-expression before 'array', why??? 
}
