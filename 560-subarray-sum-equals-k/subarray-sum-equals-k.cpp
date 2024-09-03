class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int preSum=0; 
        int count=0;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            int remove=preSum-k;
            count+=mpp[remove];
            mpp[preSum]+=1;
        }
        return count;
    }
};