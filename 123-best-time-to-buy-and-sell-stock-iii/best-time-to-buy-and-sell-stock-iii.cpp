class Solution {
public:
    int f(int i, int buy, int n, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(i==n || cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap]=max(-prices[i]+f(i+1,0,n,cap,prices,dp),f(i+1,1,n,cap,prices,dp));
        }
        
        return dp[i][buy][cap]=max(prices[i]+f(i+1,1,n,cap-1,prices,dp),f(i+1,0,n,cap,prices,dp));
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,n,2,prices,dp);
    }
};