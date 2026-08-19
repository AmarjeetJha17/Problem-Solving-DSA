class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int result = 0;
        unordered_map<int,int> f;
        f[0] = 1;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            int ques = sum - k;
            if (f.count(ques)) {
                result += f[ques];
            }
            f[sum]++;
        }
        return result;
    }
};