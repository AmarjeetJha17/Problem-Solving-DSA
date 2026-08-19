class Solution {
public:
   int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        
        int left = 0;
        for(int i=0;i<n;i++) {
            int right = sum - nums[i] - left;
            
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};