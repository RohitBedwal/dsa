class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int len = 0;
        int zero = 0;
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            if(nums[r] == 0) zero++;
            if(zero>k){
                if(nums[l] == 0) zero--;
                l++;
            }
            if(zero<=k){
                len = r - l + 1;
                maxLen = max(len, maxLen);
            }
            r++;
        }

        return maxLen;
    }
};