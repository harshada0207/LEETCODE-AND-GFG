class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        map<int, int> countMap; // Map to store counts of each card value

    // Count occurrences of each card value
    for (int card : hand) {
        countMap[card]++;
    }

    // Iterate over the count map
    while (!countMap.empty()) {
        // Find the smallest card value in the current group
        int start = countMap.begin()->first;

        // Check if it's possible to form a group starting from 'start'
        for (int i = start; i < start + groupSize; i++) {
            if (countMap.find(i) == countMap.end() || countMap[i] == 0) {
                // If any card value is missing or its count is 0, return false
                return false;
            }
            // Decrement the count of the card value
            countMap[i]--;
            if (countMap[i] == 0) {
                // If count becomes 0, erase the entry from the map
                countMap.erase(i);
            }
        }
    }

    // If all groups are successfully formed, return true
    return true;
    
        
    }
};