class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int n = s1.size();
        unordered_map<char, int> check;
        unordered_map<char, int> window;
        for (auto c : s1) {
            check[c]++;
        }
        int low = 0, high = n - 1 ;
        for (int i = low; i <= high; i++) {
            window[s2[i]]++;
        }
        while (high < s2.size()) {
            if (check == window) {
                return true;
            }
            window[s2[low]]--;
            if (window[s2[low]] == 0) {
                window.erase(s2[low]);
            }
            low++;
            high++;
            if (high < s2.size()) {
                window[s2[high]]++;
            }
        }
        return false;
    }
};