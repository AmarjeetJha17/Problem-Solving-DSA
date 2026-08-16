class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int ans = nums[0];
        int maxend = nums[0];
        int minend = nums[0];
        for (int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = maxend * nums[i];
            int v3 = minend * nums[i];
            maxend = max(v1, max(v2, v3));
            minend = min(v1, min(v2, v3));
            ans = max(ans, max(maxend, minend));
        }
        return ans;
    }
};