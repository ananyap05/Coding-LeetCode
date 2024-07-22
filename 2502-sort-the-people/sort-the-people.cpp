class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m;
        int n=names.size();
        for(int i=0;i<n;i++){
            m[heights[i]]=names[i];
        }
        vector<string> v;
        for(auto it:m){
            v.push_back(it.second);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};