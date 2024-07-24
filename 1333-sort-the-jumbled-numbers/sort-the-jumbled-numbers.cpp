class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            string s1="";
            for(int j=0;j<s.size();j++){
                char ch=s[j];
                int intch=ch-'0';
                s1+=to_string(mapping[intch]);
            }
            int c=stoi(s1);
            v.push_back({c,i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            ans.push_back(nums[v[i].second]);
        }
        return ans;
    }
};