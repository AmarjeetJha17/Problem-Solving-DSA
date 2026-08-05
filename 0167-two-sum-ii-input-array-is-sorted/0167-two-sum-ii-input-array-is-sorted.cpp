class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i = 0 , j = numbers.size() - 1;

        while(i < j){
            int pairsum = numbers[i] + numbers[j];
            if(pairsum > target){
                j --;
            } else if(pairsum < target){
                i++;
            } else{
                return {i+1, j+1};
            }
        }
        return {};
    }    
};