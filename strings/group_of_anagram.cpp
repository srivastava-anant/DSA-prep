#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key: sorted string, value: list of original anagrams
        unordered_map<string, vector<string>> groups;
        
        for (string s : strs) {
            string key = s; 
            // Sorting the string makes every anagram identical
            sort(key.begin(), key.end()); 
            
            // Push the original string into the vector at that key
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
