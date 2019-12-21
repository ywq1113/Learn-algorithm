#include<cstdio>
#include<vector>

using namespace std;

typedef struct BinarySearchTree{
    int                value;
    BinarySearchTree*  left;
    BinarySearchTree*  rightt;
} BST;

BST* test(vector<int> &nums);

BST* test(vector<int> &nums)
{
    int len = nums.size();                                                                                               
    vector<int> nums1(6);
    vector<int> nums2(6);
    if(len == 0)                                                                                                                                                                            
        return nullptr;                                                                                                                                                                     
    int mid = len/2;                                                                                                                                                                        
    while(len>=0){                                                                                                                                                                         
        int i,j,m,n;
        for(i=0, j=0;i<=mid-1;){                                                                                                                                                    
            nums1[j++] = nums[i++];
        }                                                                                                                                             
        for(m=mid+1, n=0;m!=len;){                                                                                                                                                
            nums2[n++] = nums[m++];
        }
        len /= 2;
        mid = len/2;
    }
    int k=0;
    for(auto iter=nums1.cbegin();iter!=nums1.cend()-1;++iter){
        ++k;
        printf("nums1[%d]:%d\n", k, *iter);
    }
    for(auto iter=nums2.cbegin();iter!=nums2.cend()-1;++iter){
        ++k;
        printf("nums2[%d]:%d\n", k, *iter);
    }
}

int main(){
    printf("Enter an array:\n");
    int x;
    vector<int> nums;
    while(x!=-1){
        scanf("%d",&x);
        nums.push_back(x);
    }
    //for(auto iter=nums.cbegin();iter!=nums.cend()-1;++iter)
    //    printf("%d\t", *iter);
    test(nums);
}                                                        
