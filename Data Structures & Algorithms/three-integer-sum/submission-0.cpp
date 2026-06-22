class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> sarr = nums;
        sort(sarr.begin(), sarr.end());
        
        int n = sarr.size(); // Cast size to signed int to prevent underflow bugs
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            // Skip consecutive identical fixed elements to prevent duplicate groups
            if (i > 0 && sarr[i] == sarr[i - 1]) continue;
            
            int j = n - 1;
            int k = i + 1;
            
            while (k < j) {
                if (sarr[i] == -sarr[j] - sarr[k]) {
                    ans.push_back({sarr[i], sarr[k], sarr[j]});
                    
                    k++;
                    j--;
                    
                    // Skip consecutive identical numbers to eliminate inner duplicates
                    while (k < j && sarr[k] == sarr[k - 1]) k++;
                    while (k < j && sarr[j] == sarr[j + 1]) j--;
                }
                else if (sarr[i] + sarr[j] + sarr[k] > 0) {
                    j--;
                }
                else {
                    k++;
                }
            }
        }

        return ans;
    }
};