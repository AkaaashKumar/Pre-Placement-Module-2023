class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX; 
        for (int i = 0, ii = 0; i < nums.size(); ++i) {
            target -= nums[i]; 
            for (; target <= 0; ++ii) {
                ans = min(ans, i - ii + 1); 
                target += nums[ii]; 
            }
        }
        return ans == INT_MAX ? 0 : ans; 
    }
};
