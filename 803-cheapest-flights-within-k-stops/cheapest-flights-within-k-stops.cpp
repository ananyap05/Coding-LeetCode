class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> dist(n,1e9);
        dist[src]=0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int maxi=it.first;
            int dis=it.second.second;
            int node=it.second.first;
            for(auto it:adj[node]){
                if(dis+it.second<dist[it.first] && maxi<=k){
                    dist[it.first]=dis+it.second;
                    pq.push({maxi+1,{it.first,dist[it.first]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};