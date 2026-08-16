class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int ans = nums[0];
        int best = nums[0];
        for (int i = 1; i < n; i++) {
            int sum = best + nums[i];
            best = max(nums[i], sum);
            ans = max(ans, best);
        }
        return ans;
    }
};