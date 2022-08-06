class Solution {
public:
    string frequencySort(string s) {
        int freq[128]{};
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            freq[c] = freq[c]+1;
        }        
        
        vector<pair<int, char>> pairs;
        for (int i = 0; i < 128; i++){
            if (freq[i]>0) pairs.push_back({freq[i], i});          
        }        
        
        sort(pairs.begin(), pairs.end());       
        
        string ans;
        for (auto i : pairs){
            ans = string(i.first, i.second) + ans;
            // cout << i.first << " - " << i.second << endl;
        }
        
        return ans;
    }
};

int main(){
    string s = "AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz0011223344556677889";
    Solution sol;    
    cout << sol.frequencySort(s);
    
    return 0;
}
