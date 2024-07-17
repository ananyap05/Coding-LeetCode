class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left=0;
        int right=0;
        int sum=0;
        int count=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            if(sum<=goal){
                count=count+right-left+1;
            }
            right++;
        }
        
        int goalessOne=goalLessThanOne(nums,goal-1);
        int originalGoal=count-goalessOne;
        return originalGoal;
    }

    int goalLessThanOne(vector<int> &nums,int goal){
        if(goal<0) return 0;
        int l=0;
        int r=0;
        int count=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            if(sum<=goal){
                count=count+r-l+1;
            }
            r++;
        }
        return count;
    }
};