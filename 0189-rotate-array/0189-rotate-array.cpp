class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        //reverse entire array
        int i = 0, j = n - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++; j--;
        }
        //reverse first k
        i = 0; j = k - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++; j--;
        }
        //reverse the remaining part
        i = k; j = n-1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++; j--;
        }
    }
};