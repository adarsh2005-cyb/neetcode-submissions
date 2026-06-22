class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int i = 0;
        int j = height.size() - 1;
        
        int left_max = height[i];
        int right_max = height[j];
        int total_water = 0;
        
        while (i < j) {
            // The side with the lower absolute boundary restricts the water level
            if (left_max < right_max) {
                i++; // Step inward from left
                left_max = max(left_max, height[i]); // Update left wall boundary
                total_water += left_max - height[i]; // Add trapped water above current bar
            } 
            else {
                j--; // Step inward from right
                right_max = max(right_max, height[j]); // Update right wall boundary
                total_water += right_max - height[j]; // Add trapped water above current bar
            }
        }
        
        return total_water;
    }
};