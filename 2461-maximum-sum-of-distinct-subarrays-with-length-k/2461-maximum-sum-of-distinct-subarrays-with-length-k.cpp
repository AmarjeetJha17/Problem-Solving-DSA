class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n < k) return 0;

        int low = 0;
        int high = k - 1;
        unordered_map<int, int> freq;
        long long sum = 0;
        long long result = LLONG_MIN;

        for (int i = low; i <= high; i++) {
            freq[nums[i]]++;
            sum += nums[i];
        }
        if (freq.size() == k) {
            result = max(result, sum);
        }
        while (high < n - 1) {
            sum -= nums[low];
            freq[nums[low]]--;
            if (freq[nums[low]] == 0) {
                freq.erase(nums[low]);
            }
            low++;

            high++;
            sum += nums[high];
            freq[nums[high]]++;
            if (freq.size() == k) {
                result = max(result, sum);
            }
        }
        if (result == LLONG_MIN) return 0;
        return result;
    }
};