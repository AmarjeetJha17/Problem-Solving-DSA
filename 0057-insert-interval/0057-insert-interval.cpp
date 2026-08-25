class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> result;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        for(int i=0;i<intervals.size();i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            //no overlap - before insert
            if (end < newStart) {
                result.push_back({start, end});
            }
            // overlap - merge
            else if (start <= newEnd) {
                newStart = min(start, newStart);
                newEnd = max(end, newEnd);
            }
            //no overlap - after insert
            else {
                result.push_back({newStart, newEnd});
                result.push_back({start, end});
                //push remaining elements
                for (int j=i+1;j<intervals.size();j++) {
                    result.push_back(intervals[j]);
                }
                return result;
            }
        }
        //if insert is last element
        result.push_back({newStart, newEnd});
        return result;
    }
};