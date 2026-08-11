class Solution {
public:
    int find(vector<int>& freq) {
        int maxc = -1;
        for (int i : freq) {
            maxc =  max(i, maxc);
        }
        return maxc;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(256,0);
        int low = 0;
        int result = INT_MIN;

        for (int high = 0; high < n; high++) {
            freq[s[high]]++;
            int len = high - low + 1;
            int max_int = find(freq);
            int diff = len - max_int;
            while (diff > k) {
                freq[s[low]]--;
                low++;
                len = high - low + 1;
                max_int = find(freq);
                diff = len - max_int;
            }
            len = high - low + 1;
            result = max(result, len);
        }
        return result;
    }
};