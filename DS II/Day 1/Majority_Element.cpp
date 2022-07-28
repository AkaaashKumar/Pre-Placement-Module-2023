 class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Better Solution
        map<int,int> m;
        int len=nums.size(), pos;
        for(int i=0;i<len;i++){
            m[nums[i]]++;
        if(m[nums[i]]>(len/2))
            pos=i;
        }
        return nums[pos];
    }
};
