class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0;
        int result = INT_MIN;
        unordered_map<char, int> freq;
        for (int high = 0; high < n; high++) {
            freq[s[high]]++;
            int len = high - low + 1;
            if (freq.size() != len) {
                freq[s[low]]--;
                if (freq[s[low]] == 0) {
                    freq.erase(s[low]);
                }
                low++;
                len = high - low + 1;
            }
            result = max(result, len);
        }
        if (result == INT_MIN) return 0;
        return result;
    }
};