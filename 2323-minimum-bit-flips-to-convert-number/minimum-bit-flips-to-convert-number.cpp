class Solution {
public:
    int minBitFlips(int start, int goal) {
        long ans=start^goal;
        long cnt=0;
        for(int i=0;i<31;i++){
            if(ans&(1<<i)){
                cnt=cnt+1;
            }
        }
        return cnt;
    }
};