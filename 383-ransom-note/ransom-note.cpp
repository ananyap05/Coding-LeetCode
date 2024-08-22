class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        map<char,int> m1;
        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            m1[ransomNote[i]]++;
        }
        for(auto it:m1){
            if(m[it.first]<it.second){
                return false;
            }
        }
        return true;
    }
};