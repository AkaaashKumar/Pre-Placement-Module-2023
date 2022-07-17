class Solution {
public:
    void merge(vector<int>& nums,int l, int r, int m){
        int n=nums.size();
        vector<int> ans(r-l+1);
        int i=l,j=m+1,k=0;
        while(i<=m && j<=r){
            if(nums[i]<=nums[j]){
                ans[k++]=nums[i++];
            }
            else{
                ans[k++]=nums[j++];
            }
        }
        while(i<=m){
            ans[k++]=nums[i++];
        }
        while(j<=r){
            ans[k++]=nums[j++];
        }
        for(int i=0;i<=r-l;i++){
            nums[l+i]=ans[i];
        }
    }
    void mergesort(vector<int>& nums,int l,int r){
        if(l>=r){
            return ;
        }
       int m=l+(r-l)/2;
        mergesort(nums,l,m);
        mergesort(nums,m+1,r);
        merge(nums,l,r,m);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};
