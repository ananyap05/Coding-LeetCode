class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> s1;
        int cnt=0;
        s1.push(s[0]);
        for(int i=1;i<s.size();i++){
            // s1.push(s[i]);
            if(!s1.empty() && s[i]=='a' && s1.top()=='b'){
                s1.pop();
                cnt++;
            }
            else s1.push(s[i]);
        }
        return cnt;
    }
};