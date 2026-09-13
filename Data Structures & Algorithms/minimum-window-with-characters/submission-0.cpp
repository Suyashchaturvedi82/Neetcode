class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> need,window;
        for(char c:t){
            need[c]++;
        }
        int req = need.size();
        int formed = 0;
        int l =0;
        int minlen = INT_MAX;
        int start = 0;
        for(int r = 0;r<s.size();r++){
            char c = s[r];
            window[c]++;
            if(need.count(c)&&window[c]==need[c]){
                formed++;
            }
            while(formed == req){
                if(r-l+1 <minlen){
                    minlen = r-l+1;
                    start = l;
                }
                char ch = s[l];
                window[ch]--;
                if(need.count(ch)&&window[ch]<need[ch]){
                    formed --;
                }
                l++;
            }
        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(start,minlen);

        
    }
};
