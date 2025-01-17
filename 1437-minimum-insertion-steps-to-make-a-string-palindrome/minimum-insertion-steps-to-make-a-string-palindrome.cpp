class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, string& s, string& s2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s2[j]){
            return dp[i][j]=1+f(i-1,j-1,dp,s,s2);
        }
        else{
            return dp[i][j]=0+max(f(i-1,j,dp,s,s2),f(i,j-1,dp,s,s2));
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int d=f(n-1,n-1,dp,s,s2);
        return n-d;
    }
};