class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char32_t, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        for (auto c : t) {
            if (--freq[c] < 0) return false;
        }
        return true;
    }
};