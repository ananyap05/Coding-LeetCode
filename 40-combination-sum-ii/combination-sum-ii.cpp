class Solution {
public:
    
    void helper(vector<int>& nums,int indx, int target,  vector<int> &comb, vector<vector<int>> &result)
    {
        if(target==0)
        {
            result.push_back(comb);
            return;
        }
        for(int i=indx;i<nums.size();i++)
        {
            if(i>indx && nums[i]==nums[i-1])
                continue;
            
            if(nums[i]>target)
                break;
            
            comb.push_back(nums[i]);
            helper(nums,i+1,target-nums[i],comb,result);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<int> comb;
        vector<vector<int>> result;
        helper(candidates,0,target,comb,result);
        return result;
    }
};