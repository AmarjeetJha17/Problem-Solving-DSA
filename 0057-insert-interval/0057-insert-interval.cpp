class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        //insert
        int n = intervals.size();
        vector<vector<int>> result;
        bool inserted = false;
        for(int i=0;i<n;i++) {
            int start = intervals[i][0];
            if (!inserted && start >= newInterval[0]) {
                result.push_back(newInterval);
                inserted = true;
            }
            result.push_back(intervals[i]);
        }
        if(!inserted) {
            result.push_back(newInterval);
        }
        
        //merge
        vector<vector<int>> final;
        int start1 = result[0][0];
        int end1 = result[0][1];
        for(int i=1;i<result.size();i++) {
            int start2 = result[i][0];
            int end2 = result[i][1];
            if (end1 >= start2) {
                end1 = max(end2, end1);
                continue;
            }
            final.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        final.push_back({start1, end1});
        return final;
    }
};