class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        // If the total number of cards is not divisible by the group size, it's not possible
        if (n % groupSize != 0) {
            return false;
        }

        // Priority queue to get the smallest card first
        priority_queue<int, vector<int>, greater<int>> pq;
        // Hash map to count the occurrences of each card
        unordered_map<int, int> mp;

        // Fill the priority queue and the hash map
        for (auto it : hand) {
            pq.push(it);
            mp[it]++;
        }

        // Process the cards in the priority queue
        while (!pq.empty()) {
            int topElement = pq.top();
            pq.pop();

            // If this card has already been used in forming previous groups, skip it
            if (mp.find(topElement) == mp.end()) {
                continue;
            }

            // Try to form a group starting from this card
            for (int i = 0; i < groupSize; i++) {
                if (mp.find(topElement + i) == mp.end()) {
                    return false;
                }
                mp[topElement + i]--;
                if (mp[topElement + i] == 0) {
                    mp.erase(topElement + i);
                }
            }
        }
        return true;
    }
};