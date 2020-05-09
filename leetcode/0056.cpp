class Solution {
public:
    static bool cmp(vector<int> n1, vector<int> n2) {
        return n1[0] < n2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1) return intervals;
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i=1; i<n; i++) {
            if(intervals[i][0]>end) {
                res.push_back({start, end});
                start = intervals[i][0];
            }
            end = max(intervals[i][1], end);
        }
        res.push_back({start, end});
        return res;
    }
};
