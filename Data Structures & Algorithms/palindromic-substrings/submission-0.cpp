class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        auto expand = [&](int left, int right) {
            int subCount = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                subCount++;
                left--;
                right++;
            }
            return subCount;
        };

        for (int i = 0; i < n; i++) {
            count += expand(i, i);    
            count += expand(i, i + 1);
        }

        return count;
    }
};