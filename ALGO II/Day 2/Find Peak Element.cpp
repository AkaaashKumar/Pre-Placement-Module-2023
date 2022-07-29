class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int l = 0,r = nums.size()-1,mid = l+(r-l)/2;
        while(l<=r)
        {
            int mid_l_val = mid==0?INT_MIN:nums[mid-1];
            int mid_r_val = mid==nums.size()-1?INT_MIN:nums[mid+1];
            if(nums[mid]>=mid_l_val&&nums[mid]>=mid_r_val)//峰值,因为题目中没有重复的数，因此遇到重复的数只可能发生在边界(如果数组第一个或最后一个为INT_MIN)
                return mid;
            else if(nums[mid]<mid_l_val)//nums[mid]<nums[mid-1],让r = mid-1,尽可能包含峰值
                r = mid-1;
            else if(nums[mid]<mid_r_val)//nums[mid]<nums[mid+1],让l = mid+1,尽可能包含峰值
                l = mid+1;
            mid = l+(r-l)/2;
        }
        return -1;
    }
};
