class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        int sum = 0;
        unordered_map<int,int> freq;
        freq[0] = 1;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) rem += k;
            if (freq.count(rem)) {
                result += freq[rem];
            }
            freq[rem]++;
        }
        return result;
    }
};