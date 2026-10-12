class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int w, h;
        int area = 0;
        while (i < j) {
            w = j - i;
            h = min(height[i], height[j]);
            area = max(area,(w * h));

            if (height[i] < height[j]) i++;
            else j--;
        }
        return area;
    }
};