class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(int i=0;i<word.size();i++){
            v[word[i]-'a']++;
        }
        sort(v.begin(),v.end(),greater<int>());
        int multiplier=1;
        int num=0;
        int ans=0;
        for(auto &freq:v){
            if(freq==0) break;
            ans+=freq*multiplier;
            num++;
            if(num%8==0) multiplier++;
        }
        return ans;
    }
};