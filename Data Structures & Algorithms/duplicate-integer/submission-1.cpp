class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            // If the number is already in the map, we found a duplicate
            if (m.find(nums[i]) != m.end()) {
                return true;
            }
            // CRITICAL: If it's not in the map, we must add it!
            m[nums[i]] = i; 
        }
        
        // If the loop finishes without finding duplicates, return false
        return false;
    }
};