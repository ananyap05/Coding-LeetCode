class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        sort(nums.begin(),nums.end(), [&](int a, int b){
            if(m[a]!=m[b]){
                return m[a]<m[b];
            }
            return a>b;
        });
        return nums;
    }


};