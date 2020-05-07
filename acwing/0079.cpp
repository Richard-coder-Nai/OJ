class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if(q.size() && q.front()<=i-k) {
                q.pop_front();
            }
            while(q.size() && nums[q.back()]<=nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
