//通过测试用例34/34，但是超出时间限制
class Solution {
public:
    void rotate_1(vector<int>& nums, int k) {
        int len = nums.size();
        if(k<0)
            return;
        int i;
        int tmp;
        while(k!=0){  
            int tmp = nums[len-1];        
            for(i=len-1;i>0;--i){
                nums[i] = nums[i-1];
            }
            nums[0]=tmp;
            --k;
        }
    }
   
    //三次逆序，思路比较难想 
    void rotate(vector<int>& nums, int k){
        int len = nums.size();
        if(len==1 || k<0 || len==0)
            return;
        k = k % len;
        if(k==0)
            return;
        reverse(nums.begin()+len-k,nums.end());
        reverse(nums.begin(),nums.begin()+len-k);
        reverse(nums.begin(),nums.end());

    //环状替换
    //其中while循环判断条件以及prev位于do-while循环外部容易出错
    void rotate_2(vector<int> &nums. int k){
        int len = nums.size();
        k = k%len;
        int cnt=0;
        for(int start=0;cnt!=len;++start){
            int curr = start;
            int prev = nums[start];
            do{
                int next = (curr+k)%len;
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                curr = next;
                cnt++;
            }while(i!=curr);
        }
    }

};


