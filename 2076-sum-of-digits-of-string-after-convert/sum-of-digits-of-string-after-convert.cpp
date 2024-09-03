class Solution {
public:
    int getLucky(string s, int k) {
        string sum="";
        for(int i=0;i<s.size();i++){
            sum+=to_string(s[i]-'a'+1);
        }
        for(int i=0;i<k;i++){
            int sum1=0;
            for(int i=0;i<sum.size();i++){
                sum1+=sum[i]-'0';
            }
            sum=to_string(sum1);
        }
        return stoi(sum);
    }
};