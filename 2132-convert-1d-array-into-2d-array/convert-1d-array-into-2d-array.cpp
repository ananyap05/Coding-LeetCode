class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(original.size()!=n*m) return ans;
        int t=original.size()/m;
        for(int i=0;i<original.size()-n+1;i+=t){
            vector<int> v;
            for(int j=i;j<n+i;j++){
                v.push_back(original[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};