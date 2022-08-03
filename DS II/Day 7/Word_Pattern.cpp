class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream sstrm(str);

        size_t i = 0;
        string word;
        unordered_map<char, string> pattern_idx;
        unordered_map<string, char> word_idx;
        while (sstrm >> word) {
            if (i == pattern.size()) {
                return false;
            }

            if (!word_idx[word] && pattern_idx[pattern[i]].empty()) {
                word_idx[word] = pattern[i];
                pattern_idx[pattern[i]] = word;
            } else if (word_idx[word] != pattern[i] || pattern_idx[pattern[i]] != word) {
                return false;
            }

            i++;
        }

        return i == pattern.size();
    }
};
