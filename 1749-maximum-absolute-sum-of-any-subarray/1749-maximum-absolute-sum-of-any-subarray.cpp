class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return abs(nums[0]);

        int maxans = nums[0];
        int minans = nums[0];
        int bestmax = nums[0];
        int bestmin = nums[0];

        for (int i = 1; i < n; i++) {
            //Maximum
            bestmax = max(nums[i], bestmax + nums[i]);
            maxans = max(maxans, bestmax);
            //Minimum
            bestmin = min(nums[i], bestmin + nums[i]);
            minans = min(minans, bestmin);
        }
        return max(abs(maxans), abs(minans));
    }
};