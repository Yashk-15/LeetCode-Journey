class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int count_keep = 1;
        int prev_end = intervals[0][1];

        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] >= prev_end) {
                ++count_keep;
                prev_end = intervals[i][1];
            }
        }

        return (int)intervals.size() - count_keep;
    }
};