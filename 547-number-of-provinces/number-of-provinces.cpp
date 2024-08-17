class Solution {
public:
    void bfs(int node, vector<int> adj[], vector<int>& vis){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int node1=q.front();
            q.pop();
            for(auto it:adj[node1]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        //vis[0]=1;
        //vector<int> bfs;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;
    }
};