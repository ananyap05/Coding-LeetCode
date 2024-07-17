class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int maxf=0;
        int maxlen=0;
        int hash[26]={0};
        while(right<s.size()){
            hash[s[right]-'A']++;
            maxf=max(maxf,hash[s[right]-'A']);
            if((right-left+1)-maxf>k){
                hash[s[left]-'A']--;
                left++;
            }
            if((right-left+1)-maxf<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};