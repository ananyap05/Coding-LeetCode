class Solution {
public:
    bool f(int i, vector<vector<int>>& dp, vector<int>& nums, int sum1){
        if(sum1==0) return true;
        if(i==0) return nums[i]==sum1;
        if(dp[i][sum1]!=-1) return dp[i][sum1];
        bool notpick=f(i-1,dp,nums,sum1);
        bool pick=false;
        if(nums[i]<=sum1){
            pick=f(i-1,dp,nums,sum1-nums[i]);
        }
        return dp[i][sum1]=pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        else{
            int sum1=sum/2;
            vector<vector<int>> dp(n,vector<int>(sum1+1,-1));
            return f(n-1,dp,nums,sum1);
        }
        
    }
};