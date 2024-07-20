class Solution {

    
public:
    void dfs(int node, vector<int> adjLs[],vector<int>& vis){
        vis[node]=1;
        for(auto it:adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adjLs[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis;
        for(int i=0;i<n;i++){
            vis.push_back(0);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        return cnt;
    }
};