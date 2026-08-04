class Solution {
public:
        void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0,  j = 0;
        if (n==0 || n == 1) return;
        if (nums[0] == 0) j++;
        else {
            i++; j++;
        }
        while (j < n) {
            if (nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }
            j++;
        }
    }
};