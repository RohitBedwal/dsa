class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256, -1);
        int l = 0;
        int r = 0;
        int len = 0;
        int maxLen = 0;
        while(r < s.size()){
            if(arr[s[r]] != -1){
                if(arr[s[r]] >= l){
                  l =  arr[s[r]] + 1 ;
                }
            }
            len = r - l + 1;
            maxLen = max(len, maxLen);
            arr[s[r]] = r;
            r++;

        }
        return maxLen;

    }
};