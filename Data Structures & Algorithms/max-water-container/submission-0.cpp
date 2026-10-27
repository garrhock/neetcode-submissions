class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;

        int currArea = 0, maxArea = 0;
        while (left < right ){
            int minHeight = min(heights[left], heights[right]);
            maxArea = max(maxArea, minHeight * (right - left));
            if(heights[left] > heights[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxArea;
    }
};
