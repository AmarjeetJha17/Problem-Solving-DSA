class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int ones = 0;
        int result = 0;
        unordered_map<int,int> freq;
        freq[0] = -1;
        for(int i=0;i<n;i++) {
            if (nums[i] == 0) {
                zeros++;
            } else {
                ones++;
            }
            int diff = zeros - ones;
            if (diff == 0) {
                result = max(result,i+1);
                continue;
            }
            if (freq.find(diff) == freq.end()) {
                freq[diff] = i;
            } else {
                result = max(result,i - freq[diff]);
            }
        }
        return result;
    }
};