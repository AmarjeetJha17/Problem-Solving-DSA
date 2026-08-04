class Solution {
public:
    int singleNumber(vector<int>& vec) {
        int ans = 0;
        for(int i : vec){
            ans = ans ^ i;
        }
        return ans;
    }
};