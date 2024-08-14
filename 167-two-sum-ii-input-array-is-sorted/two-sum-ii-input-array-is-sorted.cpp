class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        vector<int> v;
        while(l<=r){
            if(numbers[l]+numbers[r]==target){
                v.push_back(l+1);
                v.push_back(r+1);
                return v;
            }
            else if(numbers[l]+numbers[r]<target){
                l++;
            }
            else{
                r--;
            }
        }
        return v;
    }
};