class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maximum = 0;
        while(i<j){
            int area=(j-i)*min(heights[i],heights[j]);
            maximum=max(maximum,area);
            if(heights[i]>heights[j])j--;
            else i++;
            
        }
        return maximum;
    }
};
