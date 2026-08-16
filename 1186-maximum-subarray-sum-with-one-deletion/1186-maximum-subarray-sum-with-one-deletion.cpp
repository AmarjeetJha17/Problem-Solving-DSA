class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int ans = nums[0];
        int nodelete = nums[0];
        int onedelete = INT_MIN;
        for (int i = 1; i < n; i++) {
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;
            nodelete = max(nums[i], nodelete + nums[i]);
            int v2;
            if (prevonedelete == INT_MIN) {
                v2 = nums[i];
            }
            else {
                v2 = prevonedelete + nums[i];
            }
            onedelete = max(v2, prevnodelete);

            ans = max(ans,max(onedelete,nodelete));
        }
        return ans;
    }
};