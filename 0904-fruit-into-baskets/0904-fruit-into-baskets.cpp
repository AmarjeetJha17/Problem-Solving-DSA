class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int k  = 2;
        int n = fruits.size();
        int low = 0;
        unordered_map<int, int> freq;
        int result = INT_MIN;
        for (int high=0; high<n; high++) {
            freq[fruits[high]]++;
            while (freq.size() > k) {
                freq[fruits[low]]--;
                if (freq[fruits[low]] == 0) {
                    freq.erase(fruits[low]);
                }
                low++;
            }
            if (freq.size() <= k) {
                int len = high - low + 1;
                result = max(result, len);
            }
        }
        return result;
    }
};