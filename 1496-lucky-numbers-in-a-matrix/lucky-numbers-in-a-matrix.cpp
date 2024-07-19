class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int rMax=INT_MIN;
        int cMin=INT_MAX;
        for(int i=0;i<m;i++){
            int rMin=INT_MAX;
            for(int j=0;j<n;j++){
                rMin=min(rMin,matrix[i][j]);
            }
            rMax=max(rMax,rMin);
        }
        for(int i=0;i<n;i++){
            int cMax=INT_MIN;
            for(int j=0;j<m;j++){
                cMax=max(cMax,matrix[j][i]);
            }
            cMin=min(cMin,cMax);
        }
        if(cMin==rMax){
            return {cMin};
        }
        return {};
    }

};