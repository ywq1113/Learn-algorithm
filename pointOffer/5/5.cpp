# include <iostream>
# include <string>
# include <vector>
# include <cstdio>
using namespace std;

void ReplaceBlank(char string[], int length){
    //判断边界条件——字符串为空(即空指针和长度为0);
    //字符串没有空格;
    if(string == nullptr || length <=0)
      return;
    int originalLength = 0;
    int numberOfBlank = 0;
    int i =0;
    while(string[i]!='\0'){
      ++ originalLength;
      if (string[i]==' ')
        ++ numberOfBlank;
      ++i;
    }
    //替换之后的字符串长度
    int newLength = originalLength + numberOfBlank * 2;
    //考虑所有可能导致程序出错的情况
    if (newLength > length)
      return;
    //建立两个指针分别指向替换前和替换后的字符串末尾
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    // 找到循环终止条件——当连个指针指向同一个字符时
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
      //当p1指向为空格时，将%20复制到p2处，并使得p2向前移动对应的字符数
      if (string[indexOfOriginal] == ' ')
      {
        string[indexOfNew--] = '0';
        string[indexOfNew--] = '2';
        string[indexOfNew--] = '%';
      }
      //否则将p1的字符复制到p2处，并向前移动p2
      else
      {
        //先赋值，再执行indexOfNew--的操作
        string[indexOfNew--] = string[indexOfOriginal];
      }
      -- indexOfOriginal;
    }   
}
    
int main(){
    char s[]=" Hello World";
    ReplaceBlank(s, 20);
    cout << s << endl;
}    
