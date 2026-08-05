class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return 0;
        int  left= 0, right = n - 1;
        while (left < n - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }
        if (left == n - 1) return 0;

        while (right > 0 && nums[right] >= nums[right - 1]) {
            right--;
        }
        int subArrayMin = INT_MAX;
        int subArrayMax = INT_MIN;
        for (int i = left; i <= right; i++) {
            subArrayMin = min(subArrayMin, nums[i]);
            subArrayMax = max(subArrayMax, nums[i]);
        }
        while (left > 0 && nums[left - 1] > subArrayMin) {
            left--;
        }
        while (right < n - 1 && nums[right + 1] < subArrayMax) {
            right++;
        }
        return (right - left) + 1;
    }
};