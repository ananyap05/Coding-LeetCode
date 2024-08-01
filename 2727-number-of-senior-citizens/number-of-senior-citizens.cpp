class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0;i<details.size();i++){
            int age=0;
            string s=details[i];
            age+=(s[11]-'0')*10;
            age+=(s[12]-'0');
            if(age>60) cnt++;
        }
        return cnt;
    }
};