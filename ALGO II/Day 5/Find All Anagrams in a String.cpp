class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, freq(26); 
        for (auto& ch : p) ++freq[ch-'a']; 
        for (int i = 0; i < s.size(); ++i) {
            --freq[s[i]-'a']; 
            if (p.size() <= i) ++freq[s[i-p.size()]-'a']; 
            if (p.size() <= i+1 && all_of(freq.begin(), freq.end(), [](auto& x) {return x == 0;})) ans.push_back(i-p.size()+1); 
        }
        return ans; 
    }
};
