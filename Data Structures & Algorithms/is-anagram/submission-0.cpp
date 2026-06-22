class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: If lengths don't match, they absolutely can't be anagrams
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> countMap;
        
        // Step 2: Single loop to process both strings simultaneously
        for (int i = 0; i < s.size(); i++) {
            countMap[s[i]]++; // Add 1 for the character in s
            countMap[t[i]]--; // Subtract 1 for the character in t
        }
        
        // Step 3: Check if everything perfectly canceled out to 0
        for (auto const& [character, count] : countMap) {
            if (count != 0) {
                return false; 
            }
        }
        
        return true;
    }
};
