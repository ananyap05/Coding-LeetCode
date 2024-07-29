class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long xxor=0;
        for(int i=0;i<nums.size();i++){
            xxor=xxor^nums[i];
        }
        return xxor;
    }
};