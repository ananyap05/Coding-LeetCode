class Solution {
private: 
    static const int mod = 1e9+7;
public:
   int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subArrSum;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n; j++){
                sum += nums[j];
                subArrSum.push_back(sum);
            }
        }
        sort(subArrSum.begin(),subArrSum.end());
        int sum = 0;
        for(int i=left-1; i<right;i++)
            sum = (subArrSum[i]+sum)%mod;
        
        return sum;
    }
};