class Solution {
public:
       bool helper(vector<int>& have, vector<int>& need) {
        int n = have.size();
        for (int i = 0; i < n; i++) {
            if (have[i] < need[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        if (t.size() > s.size()) return "";
        if (t == s) return s;
        const int n = s.size();
        const int m = t.size();
        vector<int> freq(256,0);
        vector<int> needed(256,0);
        for (int i = 0; i < m; i++) {
            needed[t[i]]++;
        }
        int low = 0;
        int result = INT_MAX;
        int start = -1;
        for (int high = 0; high < n; high++) {
            freq[s[high]]++;
            while (helper(freq, needed)) {
                int len = high - low + 1;
                if (result > len) {
                    result = len;
                    start = low;
                }
                freq[s[low]]--;
                low++;
            }
        }
        if (result == INT_MAX) return "";
        return s.substr(start, result);
    }
};