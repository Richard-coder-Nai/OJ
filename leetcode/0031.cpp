class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = haystack.find(needle);
        if(res!=haystack.npos) return res;
        return -1;
    }
};
