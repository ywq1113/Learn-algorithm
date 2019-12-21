#include <iostream>

using namespace std;

class BucketSort{
public:
    void bucketSort(vector<int> &arr)
    {
        int len = arr.size();
        if(len<=1)
            return;
        int min = arr[0], max = min;
        for(int i=1;i<len;++i){
            if(min>arr[i]) min = arr[i];
            if(max<arr[i]) max = arr[i];
        }
        
        int bucketsNum = 
