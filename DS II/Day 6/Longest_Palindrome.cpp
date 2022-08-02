class Solution {
public:
    int longestPalindrome(string s) {
        if(s == "")
            return 0;
        vector<int> a(128, 0);
        for(char &c:s)
            a[c]++;
        int odd = 0;
        int res = 0;
        for(const int num:a){
            res += (num >> 1) << 1;
            if(num & 1)
                odd = 1;
        }
        return res + odd;
    }
};
