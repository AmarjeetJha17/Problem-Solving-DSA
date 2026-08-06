class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int low = 0;
    int result = 0;
    unordered_map<char, int> freq;

    for (int high = 0; high < n; high++) {
        freq[s[high]]++;

        // shrink window until it's valid (no duplicates)
        while (freq[s[high]] > 1) {
            freq[s[low]]--;
            if (freq[s[low]] == 0) {
                freq.erase(s[low]);
            }
            low++;
        }

        result = max(result, high - low + 1);
    }

    return result;
}

};