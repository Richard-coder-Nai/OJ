class Solution {
public:
    static bool cmp(int a, int b) {
        string str_a = to_string(a);
        string str_b = to_string(b);
        return str_a+str_b < str_b+str_a;
    }
    string printMinNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        
        for(auto it:nums) {
            res += to_string(it);
        }
        return res;
    }
};
