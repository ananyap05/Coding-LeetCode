class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0;
        int r=0;
        while(l<s.size()){
            if(r>t.size()) return false;
            if(s[l]==t[r]){
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return true;
    }
};