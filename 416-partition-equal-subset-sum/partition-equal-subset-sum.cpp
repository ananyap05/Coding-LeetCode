class Solution {
public:
    bool f(int i, int target, vector<vector<int>>& dp,vector<int>& nums){
        if(target==0) return true;
        if(i==0) return nums[0]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        int notpick=f(i-1,target,dp,nums);
        int pick=false;
        if(nums[i]<=target){
            pick=f(i-1,target-nums[i],dp,nums);
        }
        return dp[i][target]=pick||notpick;
    }
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        int n=nums.size();
        totSum=accumulate(nums.begin(),nums.end(),0);
        if(totSum%2!=0) return false;
        else{
            int k=totSum/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return f(n-1,k,dp,nums);
        }
    }
};