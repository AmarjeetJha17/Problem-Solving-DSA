class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n =  nums.size();
        int max_diff = INT_MAX;
        int result_sum = 0;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                if (diff < max_diff) {
                    max_diff = diff;
                    result_sum = sum;
                    if (diff == 0) return result_sum; // exact match found
                }
                if (sum == target) {
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result_sum;
    }
};