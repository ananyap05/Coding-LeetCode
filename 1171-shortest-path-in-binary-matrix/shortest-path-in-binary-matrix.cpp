class Solution {
public:
    vector<int> dx={0,-1,-1,-1,0,1,1,1};
    vector<int> dy={-1,-1,0,1,1,1,0,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1) return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        while(!q.empty()){
            int cost=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx<0 || newx>=n || newy<0 || newy>=n || grid[newx][newy]==1) continue;
                if(dist[newx][newy]>cost+1){
                    q.push({cost+1,{newx,newy}});
                    dist[newx][newy]=cost+1;
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;
    }
};