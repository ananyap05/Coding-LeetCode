class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        int product=1;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
                continue;
            }
            product*=nums[i];
        }
        //if(zero>1) return v1;
        vector<int> v1(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(zero>1) return v1;
            else if(zero==1){
                if(nums[i]!=0) v.push_back(0);
                else v.push_back(product);
            }
            else{
                v.push_back(product/nums[i]);
            }
        }
        return v;
    }
};