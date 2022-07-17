class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
    {
        int len = nums.size(), len1 = nums[0].size(), mult = len * len1;
        
        if(r * c != mult)
            return nums;
        
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < len; i++) 
        {
            for (int j = 0; j < len1; j++) 
            {
                int k = i * len1 + j;
                ans[k / c][k % c] = nums[i][j];
            }
        }

        return ans;
        
    }
};
