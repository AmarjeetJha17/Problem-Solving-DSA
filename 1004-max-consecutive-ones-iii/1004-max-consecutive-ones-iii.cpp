class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int result = INT_MIN;
        vector<int> freq(2,0);
        for (int high = 0; high < n; high++) {
            freq[nums[high]]++;
            int len = high - low + 1;
            int zero = freq[0];
            while (zero > k) {
                freq[nums[low]]--;
                low++;
                zero = freq[0];
            }
            len = high - low + 1;
            result = max(result, len);
        }
        return result;
    }
};