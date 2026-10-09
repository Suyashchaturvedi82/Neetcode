class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        int next1 = 1;
        int next2 = 0; 
        for (int i = n - 1; i >= 0; i--) {
            int current = 0;
            if (s[i] != '0') {
              
                current += next1;
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    current += next2;
                }
            }
            next2 = next1;
            next1 = current;
        }
        return next1;
    }
};