class Solution {
public:
    string reverseWords(string s) {
        if(s=="") return "";
        
        stack<string> stk;
        int n = s.size();
        
        int start = 0;
        int len = 1;

        for(int i=0; i<n; i++) {
            if(s[i]==' ') {
                stk.push(s.substr(start, len-1));
                start = i+1;
                len = 0;
            }
            len++;
        }
        stk.push(s.substr(start, len));
        
        string res = "";
        while(stk.size()>1) {
            res += stk.top();
            res += ' ';
            stk.pop();
        }
        res += stk.top();
        return res;
    }
};
