class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;
        long ans=0;
        if(dividend>=0 && divisor<0) sign=false;
        if(dividend < 0 && divisor>=0) sign=false;
        long n=abs(dividend);
        long d=abs(divisor);
        while(n>=d){
            long cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            ans+=(1<<cnt);
            n-=(d<<cnt);
        }
        if(ans==1<<31 && sign==true){
            return INT_MAX;
        }
        if(ans==1<<31 && sign==false){
            return INT_MIN;
        }
        return sign?ans:(-ans);
    }
};