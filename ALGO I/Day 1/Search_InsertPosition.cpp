class Solution {
public:
    int searchInsert(vector<int>& a, int k) {
        int low = 0, high, mid, n = a.size();
        high = n - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(a[mid] == k)return mid;
            else if(a[mid] > k)high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
