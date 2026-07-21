class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int freqCount = 0;
        vector<int> arr(26, 0);
        while(r<s.length()){
            arr[s[r] - 'A']++;
            freqCount = max(freqCount, arr[s[r] - 'A']);
            if((r - l + 1) - freqCount > k){
                arr[s[l]- 'A']--;
                freqCount = 0;
                l++;

            }
            if((r - l + 1) - freqCount <= k){
                maxFreq = max(maxFreq, r - l + 1);
                
            }
            r++;
        }
        return maxFreq;
        
    }
};