class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int start =0;
        int maxlen = 0;
        for(int i =0;i<s.length();i++){
            int len1= expand(s,i,i);
            int len2= expand(s,i,i+1);
            int len= max(len1,len2);
            if(len>maxlen){
                maxlen =len;
                start = i-(len-1)/2;
            }
        }
        return s.substr(start,maxlen);
        
    }
    private:
    int expand(const string&s,int left,int right){
        while(left>=0&&right<s.length()&&s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};
