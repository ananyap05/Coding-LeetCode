class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        long subsets=1<<n;
        vector<vector<int>> ans;
        for(int num=0;num<subsets;num++){
            vector<int> v;
            for(int i=0;i<n;i++){
                if(num&(1<<i)){
                    v.push_back(nums[i]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};