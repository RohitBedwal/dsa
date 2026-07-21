class Solution {
    private:
     int func(vector<int>& nums, int goal) {
         if (goal<0) return 0;
        int l = 0 ;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        while(r < nums.size()){
        sum += nums[r];
          while(sum > goal){
            sum = sum - nums[l];
            l++;

        }
        cnt +=( r - l + 1);
        r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

       int ans =  func(nums, goal) - func(nums, goal - 1 );
      
       return ans;
    }
};