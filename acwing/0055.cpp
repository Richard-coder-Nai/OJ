class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int s = 0;
        for(int& it:nums) {
            if(s<0) s = 0;
            s = s+it;
            res = max(res, s);
        }
        return res;
    }
};
