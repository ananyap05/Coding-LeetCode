class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int m=count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                m=max(m,count);
            }
            if(nums[i]!=1){
                count=0;
            }
        }
        return m;
    }
};