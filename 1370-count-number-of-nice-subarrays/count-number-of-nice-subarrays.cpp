class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int count=0;
        int C=0;
        while(right<nums.size()){
            if(nums[right]%2==1) count++;
            while(count>k){
                if(nums[left]%2==1) count--;
                left++;
            }
            if(count<=k){
                C+=right-left+1;
            }
            right++;
        }
        int secondcount=f(nums,k-1);
        return C-secondcount;
    }

    int f(vector<int>& nums,int k){
        int l=0;
        int r=0;
        int count=0;
        int C=0;
        while(r<nums.size()){
            if(nums[r]%2==1) count++;
            while(count>k){
                if(nums[l]%2==1) count--;
                l++;
            }
            if(count<=k){
                C+=r-l+1;
            }
            r++;
        }
        return C;
    }
};