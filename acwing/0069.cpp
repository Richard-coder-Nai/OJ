class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(i==nums[i]) return i;
        }
        return -1;
    }
};
