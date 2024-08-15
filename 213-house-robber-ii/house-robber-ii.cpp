class Solution {
public:
    int f(int i, vector<int>& dp,vector<int> nums){
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+f(i-2,dp,nums);
        int notpick=f(i-1,dp,nums);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> v1;
        vector<int> v2;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i!=0) v1.push_back(nums[i]);
            if(i!=n-1) v2.push_back(nums[i]);
        }
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        int ans1=f(n-2,dp1,v1);
        int ans2=f(n-2,dp2,v2);
        return max(ans1,ans2);
    }
};