class Solution {
public:
    int counter[256] = {0};
    char firstNotRepeatingChar(string s) {
        for(char it:s) counter[it]++;
        for(char it:s) {
            if(counter[it]==1) return it;
        }
        return '#';
    }
};
