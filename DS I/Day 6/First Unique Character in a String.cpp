class Solution {
public:
      int firstUniqChar(string s) {
        map<char, int> G; // Map char to its count in the string
        for (int i{}; i < s.size(); i++) { 
      G[s[i]]++;  // Everytime the character appears in the string, add one to its count
    } 
        for (int i{}; i < s.size(); i++) { // Start traversing the string from the beginning. 
      if (G[s[i]] == 1) return i; // If the count of the char is equal to 1, it is the first distinct character in the list.
    } 
        return -1;
    }
};
