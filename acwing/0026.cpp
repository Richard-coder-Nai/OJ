#include<bitset>
class Solution {
public:
    int NumberOf1(int n) {
        bitset<32> bs(n);
        return bs.count();
    }
};
