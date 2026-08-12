class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length()) return {};
        vector<int> result;
        int n = s.length();
        int k = p.length();
        unordered_map<char, int> check;
        unordered_map<char, int> window;
        for (auto c : p) {
            check[c]++;
        }
        int low = 0, high = k - 1;
        for (int i = low; i <= high; i++) {
            window[s[i]]++;
        }
        while (high < n) {
            if (check == window) {
                result.push_back(low);
            }
            window[s[low]]--;
            if (window[s[low]] == 0) {
                window.erase(s[low]);
            }
            low++;
            high++;
            if (high < n) {
                window[s[high]]++;
            }
        }
        return result;
    }
};