class Solution {
private:
    bool chk_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowel_position = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        unordered_map<int, int> last_occured;
        last_occured[0] = -1;  // Initial state with no vowels
        
        int cur = 0;  // Bitmask to track the parity of vowel counts
        int max_len = 0;

        for (int r = 0; r < s.size(); r++) {
            if (chk_vowel(s[r])) {
                // Toggle the bit for the current vowel
                cur ^= (1 << vowel_position[s[r]]);

                // Uncomment it to see the bits changing
                // bitset<5> b(cur);
                // cout<<b<<endl;
            }

            // If the current state has been seen before, calculate the length
            if (last_occured.find(cur) != last_occured.end()) {
                max_len = max(max_len, r - last_occured[cur]);
            } 
            // Store the first occurrence of this state
            else {
                last_occured[cur] = r;
            }
        }

        return max_len;
    }
};