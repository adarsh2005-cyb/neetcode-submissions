#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;
        
        while (st < end) {
            int mid = st + (end - st) / 2; // Fixed: Added type int and semicolon
            
            // Look only at the relationship between mid and end!
            if (nums[mid] > nums[end]) {
                // Minimum must be on the right side
                st = mid + 1;
            } 
            else {
                // Minimum is mid or to the left of mid
                end = mid; 
            }
        }
        
        // When st == end, they are both pointing exactly at the minimum element
        return nums[st];
    }
};