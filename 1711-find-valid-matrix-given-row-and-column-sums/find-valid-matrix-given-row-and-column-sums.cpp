class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int m=rowSum.size();
        int n=colSum.size();
        vector<vector<int>> v(m,vector<int>(n,0));
        int i=0, j=0;
        while(i<m && j<n){
            v[i][j]=min(rowSum[i],colSum[j]);
            rowSum[i]-=v[i][j];
            colSum[j]-=v[i][j];
            if(rowSum[i]==0){
                i++;
            }
            if(colSum[j]==0){
                j++;
            }
        }
        return v;
    }
};