class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int res=0,left=0,right=height.size()-1;
        while(left<right)
        {
            int lower=height[height[left]<height[right]?left++:right--];
            res=max(res,(right-left+1)*lower);
        }
        return res;
    }
};
