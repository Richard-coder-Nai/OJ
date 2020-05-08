class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(table.count(nums[i])) {
                return {table[nums[i]], i};
            }
            table[target-nums[i]] = i;
        }
        return {-1, -1};
    }
};
